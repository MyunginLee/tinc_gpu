#ifndef BUFFERMANAGER_HPP
#define BUFFERMANAGER_HPP

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

#include <memory>
#include <mutex>
#include <vector>

namespace tinc {

/**
 * The BufferManager class provides a thread safe memory buffer that can do
 * fast reads as it requires only a pointer swap. It provides double buffering
 * by default, but it allows for a larger number of write buffers in cases
 * where concurrent writes would otherwise block the other writes.
 */
template <class DataType> class BufferManager {
public:
  const int mSize;

  BufferManager(uint16_t size = 2) : mSize(size) {
    assert(size > 1);
    for (uint16_t i = 0; i < mSize; i++) {
      mData.emplace_back(std::make_shared<DataType>());
    }
  }
  /**
   * @brief Get current buffer for reading
   * @param markAsUsed if false, the returned buffer keeps its "new" status
   * @return a pointer to the data
   */
  std::shared_ptr<DataType> get(bool markAsUsed = true) {
    std::unique_lock<std::mutex> lk(mDataLock);
    if (markAsUsed) {
      mNewData = false;
    }
    return mData[mReadBuffer];
  }

  /**
   * @brief Get current buffer for reading checking if data is new
   * @param isNew this is set to true if data returned is "new", false otherwise
   * @return
   */
  std::shared_ptr<DataType> get(bool *isNew) {
    std::unique_lock<std::mutex> lk(mDataLock);
    if (mNewData) {
      *isNew = true;
      mNewData = false;
    } else {
      *isNew = false;
    }
    return mData[mReadBuffer];
  }

  /**
   * @brief Get a pointer to a writable buffer
   *
   * When done writing this buffer, call doneWriting()
   */
  std::shared_ptr<DataType> getWritable() {
    std::unique_lock<std::mutex> lk(mDataLock);
    // TODO add timeout?
    while (mData[mWriteBuffer].use_count() > 1) {
      mWriteBuffer++;
      if (mWriteBuffer == mReadBuffer) {
        mWriteBuffer++;
      }
      if (mWriteBuffer >= mSize) {
        mWriteBuffer = 0;
      }
    }
    return mData[mWriteBuffer];
  }

  /**
   * @brief Mark a buffer as ready to read
   * @param buffer The buffer previously received from getWritable()
   *
   * The buffer provided must come from getWritable() otherwise behavior is
   * undefined.
   */
  void doneWriting(std::shared_ptr<DataType> buffer) {
    std::unique_lock<std::mutex> lk(mDataLock);
    mReadBuffer = std::distance(mData.begin(),
                                std::find(mData.begin(), mData.end(), buffer));
    assert(mReadBuffer < mData.size());
    mNewData = true;
  }
  /**
   * @brief Check if there are buffers that have been written but not read
   */
  bool newDataAvailable() {
    std::unique_lock<std::mutex> lk(mDataLock);
    return mNewData;
  }

protected:
  std::vector<std::shared_ptr<DataType>> mData;

  std::mutex mDataLock;
  bool mNewData{false};
  uint16_t mReadBuffer{0};
  uint16_t mWriteBuffer{1};

private:
};

} // namespace tinc

#endif // AL_BUFFERMANAGER_HPP
