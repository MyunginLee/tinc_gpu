#ifndef DISKBUFFERNETCDF_HPP
#define DISKBUFFERNETCDF_HPP

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

#include "al/types/al_VariantValue.hpp"
#include "tinc/DiskBuffer.hpp"

#ifdef TINC_HAS_NETCDF
#include <netcdf.h>
#endif

#include <map>
#include <vector>

namespace tinc {

/*
#define NC_NAT          0
#define NC_BYTE         1
#define NC_CHAR         2
#define NC_SHORT        3
#define NC_INT          4
#define NC_LONG         NC_INT
#define NC_FLOAT        5
#define NC_DOUBLE       6
#define NC_UBYTE        7
#define NC_USHORT       8
#define NC_UINT         9
#define NC_INT64        10
#define NC_UINT64       11
#define NC_STRING       12
*/

// deprecated: use al::VariantType instead
typedef enum {
  NAT = 0,
  BYTE = 1,
  CHAR = 2,
  SHORT = 3,
  INT = 4,
  LONG = INT,
  FLOAT = 5,
  DOUBLE = 6,
  UBYTE = 7,
  USHORT = 8,
  UINT = 9,
  INT64 = 10,
  UINT64 = 11,
  STRING = 12
} NetCDFTypes;

/**
 * @brief A representation of a single vector of NetCDF data
 */
class NetCDFData {
public:
  ~NetCDFData();

  /**
   * @brief get NC data type for this data
   * @return a value from al::VariantType enum, which matches NC types
   */
  al::VariantType getType();
  void setType(al::VariantType type);

  template <class DataType> std::vector<DataType> &getVector() {
    if (!dataVector) {
      std::cerr << "ERROR: Type for data not set. Will crash." << std::endl;
    }
    return *static_cast<std::vector<DataType> *>(dataVector);
  }

  /**
   * @brief attributes written/read to/from NetCDF file
   */
  std::map<std::string, al::VariantValue> attributes;
  /**
   * @brief attributes written/read to/from NetCDF file
   */
  void *dataVector{nullptr};

private:
  al::VariantType ncDataType{al::VariantType::VARIANT_NONE};

  void deleteData();
};

/**
 * @brief A DiskBuffer that reads and decodes NetCDF4 files.
 *
 * This class will do nothing if TINC was not built with NetCDF support
 *
 */
// TODO we should have the option to check if there is already a file on disk
// and start with that data.
class DiskBufferNetCDFData : public DiskBuffer<NetCDFData> {
public:
  DiskBufferNetCDFData(std::string id, std::string fileName = "",
                       std::string relPath = "", std::string rootPath = "",
                       uint16_t size = 2)
      : DiskBuffer<NetCDFData>(id, fileName, relPath, rootPath, size) {
#ifndef TINC_HAS_NETCDF
    std::cerr << "ERROR: DiskBufferNetCDFDouble built without NetCDF support"
              << std::endl;
    assert(0 == 1);
#endif
  }

  /**
   * @brief Set name of variable in NetCDF file
   * @param name
   */
  // TODO propagate this to TincClients
  void setDataFieldName(std::string name) { mDataFieldName = name; }

protected:
  virtual bool parseFile(std::string fileName,
                         std::shared_ptr<NetCDFData> newData) override;

  bool encodeData(std::string fileName, NetCDFData &newData) override;

  std::string mDataFieldName{"data"};
};

} // namespace tinc

#endif // DISKBUFFERNETCDF_HPP
