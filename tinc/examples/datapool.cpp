#include "tinc/DataPoolJson.hpp"
#include "tinc/ProcessorCpp.hpp"

#include "nlohmann/json.hpp"
using json = nlohmann::json;

#include <fstream>

void createData(tinc::ParameterSpace &ps) {
  auto dirDim = ps.newDimension("dirDim", tinc::ParameterSpaceDimension::ID);
  uint8_t values[] = {0, 2, 4, 6, 8};
  dirDim->appendSpaceValues(values, 5, "datapool_directory_");

  auto internalValuesDim = ps.newDimension("internalValuesDim");
  float internalValues[] = {-0.3f, -0.2f, -0.1f, 0.0f, 0.1f, 0.2f, 0.3f};
  internalValuesDim->appendSpaceValues(internalValues, 7);

  // The running path for the parameter space is determined by 'dirDim'
  ps.setCurrentPathTemplate("%%dirDim%%");

  // Make sure our filesystem is fresh
  ps.cleanDataDirectories();

  // Make a simple processor to generate data in the parameter space
  tinc::ProcessorCpp dataCreator;
  dataCreator.processingFunction = [&]() {
    // Append values into the file
    json j;
    std::ifstream in("datapool_data.json");
    if (in.good()) {
      in >> j;
      in.close();
    }
    j["value"].push_back(
        dataCreator.configuration["internalValuesDim"].get<double>() *
        (1.0 +
         std::stoi(
             dataCreator.configuration["dirDim"].get<std::string>().substr(
                 sizeof("datapool_directory_") - 1))));

    std::ofstream out("datapool_data.json");
    if (out.good()) {
      out << j;
    }
    return true;
  };
  dataCreator.setVerbose(false);

  // Generate data
  ps.sweep(dataCreator);
}

int main() {

  // Create parameter space with two dimensions, one that affects the directory
  // and another that affects data within a file.
  tinc::ParameterSpace ps;
  // Create data associated with the parameter space
  createData(ps);

  // Print data just for reference to understand slicing
  for (const auto &directory : ps.runningPaths()) {
    std::ifstream in(directory + "/datapool_data.json");
    std::cout << " ***** FILE: " << directory + "/datapool_data.json"
              << std::endl;
    if (in.is_open()) {
      std::string line;
      while (std::getline(in, line)) {
        std::cout << line << std::endl;
      }
      in.close();
    }
  }
  auto internalValuesDim = ps.getDimension("internalValuesDim");

  // Now we will access the data
  tinc::DataPoolJson dp(ps);
  dp.registerDataFile("datapool_data.json", "internalValuesDim");

  // You can write slices disk (with automatic caching)
  internalValuesDim->setCurrentIndex(0);
  std::cout << "Current file: " << dp.getCurrentFiles()[0] << std::endl;

  auto dataSliceFile = dp.createDataSlice("value", "internalValuesDim");
  std::cout << "Slice written to " << dataSliceFile << std::endl;

  internalValuesDim->setCurrentIndex(1);
  std::cout << "Current file: " << dp.getCurrentFiles()[0] << std::endl;
  dataSliceFile = dp.createDataSlice("value", "internalValuesDim");
  std::cout << "Slice written to " << dataSliceFile << std::endl;

  // Or you can request a slice to memory.
  // By default this will write a file or read the file if already produced
  //  size_t readCount = 0;

  float slice[5];
  internalValuesDim->setCurrentIndex(0);
  std::cout << "Current file: " << dp.getCurrentFiles()[0] << std::endl;
  dp.readDataSlice("value", "internalValuesDim", slice, 5);
  for (size_t i = 0; i < 5; i++) {
    std::cout << slice[i] << " ";
  }
  std::cout << std::endl;
  internalValuesDim->setCurrentIndex(1);
  std::cout << "Current file: " << dp.getCurrentFiles()[0] << std::endl;
  dp.readDataSlice("value", "internalValuesDim", slice, 5);
  for (size_t i = 0; i < 5; i++) {
    std::cout << slice[i] << " ";
  }
  std::cout << std::endl;
  internalValuesDim->setCurrentIndex(2);
  std::cout << "Current file: " << dp.getCurrentFiles()[0] << std::endl;
  dp.readDataSlice("value", "internalValuesDim", slice, 5);
  for (size_t i = 0; i < 5; i++) {
    std::cout << slice[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
