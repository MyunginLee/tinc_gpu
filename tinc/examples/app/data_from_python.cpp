#include "al/app/al_DistributedApp.hpp"
#include "al/graphics/al_Font.hpp"

#include "tinc/TincServer.hpp"
#include "tinc/DiskBufferJson.hpp"

using namespace al;
using namespace tinc;

struct TincApp : DistributedApp {
  TincServer tserv;

  DiskBufferJson backgroundBuffer{"background", "background.json"};
  DiskBufferJson dataBuffer{"sine_data", "output.json"};

  // Local data that will be filled from disk buffer
  std::string textString;
  std::string currentFile;
  Color bgColor{0.4};
  VAOMesh mesh;

  void onInit() override {

    // Expose the buffers through the TINC server
    tserv << backgroundBuffer << dataBuffer;
    tserv.start();
  }

  void onAnimate(double dt) override {

    // Update data is new disk buffers are available.
    if (backgroundBuffer.newDataAvailable()) {
      auto data = backgroundBuffer.get();
      // It's a good idea to validate
      if (data->is_array() && data->size() == 3) {
        auto bgList = data->get<std::vector<float>>();
        bgColor = Color(bgList[0], bgList[1], bgList[2]);
      }
    }

    if (dataBuffer.newDataAvailable()) {
      std::cout << "New data available. Swapping buffer" << std::endl;
      auto &data = *dataBuffer.get();
      // Make test string from random values
      textString = data["random"].dump();
      // Make a mesh from the values in the two lists
      mesh.reset();
      mesh.primitive(Mesh::LINE_STRIP);
      auto sines = data["sines"];
      int counter = 0;
      for (auto val : sines) {

        mesh.vertex(data["random"].at(counter++).get<double>(),
                    val.get<double>(), -4.0);
      }
      mesh.update();

      // Get current cache file used to display the name
      currentFile = dataBuffer.getCurrentFileName();
    }
  }

  void onDraw(Graphics &g) override {
    g.clear(bgColor);

    FontRenderer::render(g, textString.c_str(), {-1, -0.5, -4}, 0.1);
    FontRenderer::render(g, currentFile.c_str(), {-1, -0.7, -4}, 0.1);

    g.color(1.0);
    g.draw(mesh);
  }

  void onExit() override { tserv.stop(); }
};

int main() {
  TincApp().start();
  return 0;
}
