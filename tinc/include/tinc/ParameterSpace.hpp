#ifndef PARAMETERSPACE_HPP
#define PARAMETERSPACE_HPP

/*
 * Copyright 2020 AlloSphere Research Group
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 *   3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from this
 * software without specific prior written permission.
 *
 *        THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * authors: Andres Cabrera
 */

#include "al/io/al_Socket.hpp"
#include "tinc/CacheManager.hpp"
#include "tinc/IdObject.hpp"
#include "tinc/ParameterSpaceDimension.hpp"
#include "tinc/Processor.hpp"

#include <functional>
#include <memory>
#include <string>
#include <thread>
#include <vector>

namespace tinc {
/**
 * @brief The ParameterSpace class contains a set of ParameterSpaceDimensions
 * and organizes access to them
 *
 * Parameter spaces can be linked to specific directories in the file system.
 * This can be useful to locate data according to paramter values. For example
 * when the data is a result of a parameter sweep that generated multiple
 * directories. See setCurrentPathTemplate() and generateRelativeRunPath for
 * more information.
 */
class ParameterSpace : public IdObject {
  friend class TincProtocol;

public:
  ParameterSpace(std::string id = std::string()) { setId(id); }
  ~ParameterSpace();
  // disallow copy constructor
  ParameterSpace(const ParameterSpace &other) = delete;
  // disallow copy assignment
  ParameterSpace &operator=(const ParameterSpace &other) = delete;

  /**
   * @brief Get a registered ParameterSpaceDimension by name
   * @param name
   * @param group
   * @return the dimension or nullptr if not found
   */
  ParameterSpaceDimension *getDimension(std::string name,
                                        std::string group = "");

  /**
   * @brief create and register a new dimension for this parameter space
   * @param name dimension name
   * @param type representation type for the value
   * @param parameterType data type and behavior of parameter
   * @return the newly created dimension.
   */
  ParameterSpaceDimension *
  newDimension(std::string name,
               ParameterSpaceDimension::RepresentationType type =
                   ParameterSpaceDimension::VALUE,
               ParameterType parameterType = ParameterType::PARAMETER_FLOAT,
               std::string group = "");

  /**
   * @brief Register an existing dimension with the parameter space
   * @param dimension dimension to register
   * @param src original socket that message came from * /
   * @return pointer to the registered dimension
   *
   * If the dimension was already registered, the data from the incoming
   * dimension is copied to the existing dimension and the existing dimension is
   * returned. You must always use the returned shared_ptr instead of the
   * shared_ptr passed
   */
  ParameterSpaceDimension *
  registerDimension(std::shared_ptr<ParameterSpaceDimension> &dimension,
                    al::Socket *src = nullptr);

  /**
   * @brief remove dimension from list of registered dimensions
   * @param name dimension name
   * @param group dimension group
   * @param invoked true only if called by TincProtocol's removeParameter
   * @param src original socket that message came from
   */
  void removeDimension(std::string name, std::string group = "",
                       bool invoked = false, al::Socket *src = nullptr);

  /**
   * @brief get list of registered dimensions
   */
  std::vector<ParameterSpaceDimension *> getDimensions();

  /**
   * @brief Returns all the paths that are used by the whole parameter space
   * @param fixedDimensions only use paths for the current values of these
   * dimensions
   */
  std::vector<std::string> runningPaths(
      std::vector<std::string> fixedDimensions = std::vector<std::string>());

  /**
   * @brief Get relative filesystem path for current parameter values
   * @return
   *
   * Generated according to generateRelativePath()
   */
  std::string getCurrentRelativeRunPath();

  /**
   * @brief Resolve common id for dimensions
   * @param dims
   * @param indeces map containing override values
   * @return
   *
   * When dimensions have the same value mapped to multiple ids, the id can
   * be resolved through the combination with other dimensions
   */
  std::string getCommonId(std::vector<std::string> dimNames = {},
                          std::map<std::string, size_t> indices = {});

  static std::string
  getCommonId(std::vector<ParameterSpaceDimension *> dimensions,
              std::map<ParameterSpaceDimension *, size_t> indices);

  /**
   * @brief Returns the names of all dimensions
   */
  std::vector<std::string> getDimensionNames();

  /**
   * @brief Determines if dimensionName is a dimension that affeects the
   * filesystem
   * @param dimensionName
   * @return true if changes in dimension affect the filesystem paths
   */
  bool isFilesystemDimension(std::string dimensionName);

  /**
   * @brief removes all dimensions from parameter space
   */
  void clear();

  /**
   * @brief increment to next index from index array
   * @param currentIndices
   * @return true when no more indices to process
   */
  bool incrementIndices(std::map<std::string, size_t> &currentIndices);

  /**
   * @brief run a Processor with information and caching from the parameter
   * space
   * @param processor processor to run
   * @param args additional or override arguments to pass to the processor
   * @param dependencies processor to run
   * @param recompute force recompute if true
   * @return return value from the processor
   *
   * The args map can provide additional configuration arguments to the
   * processor or can replace the current value of a parameter with that name
   */
  bool
  runProcess(Processor &processor,
             const std::map<std::string, al::VariantValue> &args = {},
             const std::map<std::string, al::VariantValue> &dependencies = {},
             bool recompute = false);

  /**
   * @brief sweep the parameter space across all or specified dimensions
   * @param processor processor to sweep with parameter space
   * @param dimensionNames names of dimensions to sweep, all if empty
   * @param recompute force recompute if true
   */
  void sweep(Processor &processor, std::vector<std::string> dimensionNames = {},
             std::map<std::string, al::VariantValue> dependencies = {},
             bool recompute = false);

  /**
   * @brief Run a parameter sweep asynchronously (non-blocking)
   *
   * This function's parameters are identical to sweep()
   */
  void sweepAsync(Processor &processor,
                  std::vector<std::string> dimensionNames = {},
                  std::map<std::string, al::VariantValue> dependencies = {},
                  bool recompute = false, int numThreads = 1);
  /**
   * @brief Interrupts an asynchronous parameter sweep after current computation
   * is done
   */
  void stopSweep();

  /**
   * @brief Create necessary filesystem directories to be populated by data
   * @return true if successfully created (or checked existence) of
   * directories.
   */
  bool createDataDirectories();

  /**
   * @brief Prepare data directoires, leaving them empty if they had any
   * contents
   * @return true if all directories could be cleaned and recreated.
   *
   * Use this function with extreme care, as it can be very destructive!!
   */
  bool cleanDataDirectories();

  /**
   * @brief Remove all directories related to this parameter space
   * @return true if all directories could be cleaned and recreated.
   *
   * Use this function with extreme care, as it can be very destructive!!
   */
  bool removeDataDirectories();

  /**
   * @brief Load parameter space dimensions from disk file
   * @param ncFile
   * @return true if reading was succesful
   *
   * The file is loaded relative to 'rootPath'. Dimension found in the file are
   * added to the current parameter space if a dimension with that name already
   * exists, it is replaced.
   */
  bool readFromNetCDF(std::string ncFile = "parameter_space.nc");

  /**
   * @brief write parameter space dimensions to netCDF file.
   * @param fileName
   * @return true if writing was succesful
   */
  bool writeToNetCDF(std::string fileName = "parameter_space.nc");

  /**
   * @brief Read dimensions from parameter space netcdf file
   * @param filename
   * @param[out] newDimensions
   * @return true if read was succesful
   */
  bool readDimensionsInNetCDFFile(
      std::string filename,
      std::vector<std::shared_ptr<ParameterSpaceDimension>> &newDimensions);

  /**
   * @brief Set the parameter space's root path
   * @param rootPath
   */
  void setRootPath(std::string rootPath, al::Socket *src = nullptr);

  /**
   * @brief Get root path for the parameter space
   * @return
   *
   * Path constructed thgouth the path template and the
   * generateRelativeRunPath() should be relative to this path.
   */
  std::string getRootPath();

  /**
   * @brief map names provided to getDimension() to internal data names
   *
   * You can also use this map to display user friendly names when displaying
   * parameters. Changing this is not thread safe.
   */
  std::map<std::string, std::string> parameterNameMap;

  /**
   * @brief Set path template
   * @param pathTemplate
   *
   * By default, the generateRelativePath() function will use this template to
   * generate the path, but this path might be ignored if it is not used in the
   * new generateRelativeRunPath() function.
   * You must either call this function or set a generateRelativeRunPath
   * function to have the parameter space linked to a location in the
   * filesystem.
   *
   * See resolveFilename() for information on how the template is resolved.
   */
  void setCurrentPathTemplate(std::string pathTemplate,
                              al::Socket *src = nullptr) {
    mCurrentPathTemplate = pathTemplate;
    modified(src);
  }

  /**
   * @brief Return current path template
   * @return
   */
  std::string getCurrentPathTemplate() { return mCurrentPathTemplate; }

  /**
   * @brief function that generated relative paths according to current values.
   *
   * You must either set this function or use setCurrentPathTemplate() to have
   * the parameter space linked to a location in the filesystem.
   * Only override this function if using a path template is insufficient. If
   * this function is replaced, the path template will have noeffect unless it
   * is specifically used in the new function.
   *
   * This function should always return the path ending with a drectory
   * separator.
   */
  std::function<std::string(std::map<std::string, size_t>, ParameterSpace *)>
      generateRelativeRunPath = [&](std::map<std::string, size_t> indices,
                                    ParameterSpace *ps) {
        std::string path = ps->resolveTemplate(mCurrentPathTemplate, indices);
        return al::File::conformDirectory(al::File::conformPathToOS(path));
      };

  /**
   * @brief onSweepProcess is called after a sample completes processing as part
   * of a sweep
   */
  std::function<void(double progress)> onSweepProcess;

  /**
   * @brief resolve filename template according to current parameter values
   * @param fileTemplate
   * @param indeces map of indeces that override current values.
   * @return resolved string
   *
   * You can use %% to delimit dimension names, e.g. "value_%%ParameterValue%%"
   * where %%ParameterValue%% will be replaced by the current value (in the
   * correct representation as ID, VALUE or INDEX) of the dimension whose id is
   * "ParameterValue". You can specify a different representation than the one
   * set for the ParameterSpaceDimension by adding it following a ':'. For
   * example:
   * "value_%%ParameterValue:INDEX%%" will replace "%%ParameterValue:INDEX%%"
   * with the current index for ParameterValue.
   * For parameters that have mutiple ids for the same value, you can specify
   * any muber of parameters separated by commas. the function getCommonId()
   * will be called. For example, for %%param1,param2%% the common id for the
   * their current values will be inserted. Any representation type (ID, VALUE,
   * INDEX) is ignored, as only ids are used. Using this method can be useful as
   * it can avoid having to define a custom generateRelativeRunPath() function
   */
  std::string resolveTemplate(std::string fileTemplate,
                              std::map<std::string, size_t> indeces = {});

  static std::string resolveTemplate(
      std::string fileTemplate,
      std::vector<ParameterSpaceDimension *> dimensions,
      std::map<ParameterSpaceDimension *, size_t> indecesOverride = {});

  /**
   * @brief Enable caching for the parameter space
   * @param cachePath path relative to root path
   *
   * Caching will be used when calling runProcess() and sweep()
   * You should use cachePath as a relative path to rootPath
   */
  void enableCache(std::string cachePath);

  CacheEntry cacheEntryForProcessor(Processor &processor);

  /**
   * @brief Disable caching for the parameter space
   */
  void disableCache();

  /**
   * @brief get CacheManager object
   * @return nullptr if cache not enabled
   *
   * Use with care, as some functionality within CacheManager will not
   * propagate correctly if set from object. As a rule of thumb use this
   * object to query rather than configure the cache manager.
   */
  std::shared_ptr<CacheManager> getCacheManager() { return mCacheManager; }

  void print(std::ostream &stream = std::cout);

  /**
   * @brief callback when the value in any particular dimension changes.
   *
   * You can get the new and previous values through changedDimension.
   * The values are contained within the parameterMeta() object and you will
   * need to cast to the appropriate type, for example:
@code
    float previous = dynamic_cast<Parameter
*>(changedDimension->parameterMeta())
              ->getPrevious();
    float newValue = dynamic_cast<Parameter
*>(changedDimension->parameterMeta())
              ->get();
@endcode
   * You should use this callback whenever you need to know the specific
   * dimension that has changed. For this reason, you should not update
   * processor configurations from here, as this function will not be called,
   * except when a particular dimension has changed.
   */
  std::function<void(ParameterSpaceDimension *changedDimension,
                     ParameterSpace *ps)>
      onValueChange =
          [](ParameterSpaceDimension *changedDimension, ParameterSpace *ps) {};

  // Currently allows only one TincServer. Should we provision for more?
  /**
   * This callback is called when dimension metadata has changed or a
   * dimension is added. When a dimension is new, the new dimension has not yet
   * been added to the parameter space.
   *
   * If dimension was not registered correctly we will be in an inconsistent
   * state, and user will be warned. assert will fail to trigger crash on debug
   * builds.
   */
  std::function<void(ParameterSpaceDimension *changedDimension,
                     ParameterSpace *ps, al::Socket *src)>
      onDimensionRegister = [](ParameterSpaceDimension *changedDimension,
                               ParameterSpace *ps, al::Socket *src = nullptr) {
        // Avoid compiler warnings
        (void)changedDimension;
        (void)ps;
        (void)src;
      };

  /**
   * This callback is called when dimension is removed
   */
  std::function<void(ParameterSpaceDimension *changedDimension,
                     ParameterSpace *ps, bool invoked, al::Socket *src)>
      onDimensionRemove = [](ParameterSpaceDimension *changedDimension,
                             ParameterSpace *ps, bool invoked = false,
                             al::Socket *src = nullptr) {};

protected:
  /**
   * @brief update current position to value in dimension ps
   * @param ps
   *
   * This function checks if new dataset directory needs a reload of
   * parameter_space.nc and processes the parameter space changes
   */
  void updateParameterSpace(ParameterSpaceDimension *ps);

  bool executeProcess(Processor &processor, bool recompute);

  // TODO Currently allows only one TincServer/TincClient. Should we provision
  // for more?
  /**
   * This callback is called when dimension metadata has changed or a
   * dimension is added. When a dimension is new, the new dimension has not yet
   * been added to the parameter space.
   *
   */
  // std::function<void(ParameterSpaceDimension *changedDimension,
  //                    ParameterSpace *ps, al::Socket *src)>
  //     onDimensionRegister = [](ParameterSpaceDimension *changedDimension,
  //                              ParameterSpace *ps, al::Socket *src = nullptr)
  //                              {

  //     };

  std::vector<std::shared_ptr<ParameterSpaceDimension>> mDimensions;

  std::vector<std::shared_ptr<ParameterSpaceDimension>> mDimensionsOwned;

  /// Stores template to generate current path using resolveFilename()
  std::string mCurrentPathTemplate;

  std::vector<std::shared_ptr<std::thread>> mAsyncProcessingThreads;
  std::shared_ptr<ParameterSpace> mAsyncPSCopy;

  bool mSweepRunning{false};

  // Subdirectories that have a parameter space file in them.
  std::map<std::string, std::string> mSpecialDirs;

  std::shared_ptr<CacheManager> mCacheManager;

  /**
   * @brief Filesystem root path for parameter space
   *
   * This root path is where the root parameter space should be localted and
   * should contain all data directories
   */
  std::string mRootPath;

private:
  std::mutex mDimensionsLock;
};
} // namespace tinc

#endif // PARAMETERSPACE_HPP
