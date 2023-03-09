#ifndef CPPPROCESSOR_HPP
#define CPPPROCESSOR_HPP

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

#include "tinc/Processor.hpp"

#include <functional>

namespace tinc {

/**
 * @brief A class to manage C++ computation within TINC
 *
 * The processingFunction function is called by process(). You must set this
 * function, otherwise an exception will be raised.
 *
 * @code
ProcessorCpp proc("proc1");

proc.processingFunction = [&]() {
    // Do processing here and return status
    return true;
};

proc.process();
@endcode
 *
 * A ProcessorCpp object process() function has a default of true for
 * forceRecompute, but it will still be false when used within a ProcessorChain,
 * so you will need to force recomputation of the chain for the ProcessCpp to be
 * executed.
 */
class ProcessorCpp : public Processor {
public:
  ProcessorCpp(std::string id = "");

  bool process(bool forceRecompute = false) override;

  std::function<bool(void)> processingFunction;

private:
};

} // namespace tinc

#endif // CPPPROCESSOR_HPP
