#ifndef TINCCLIENT_HPP
#define TINCCLIENT_HPP

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
 * authors: Andres Cabrera, Kon Hyong Kim
 */

#include <deque>

#include "al/io/al_Socket.hpp"
#include "al/protocol/al_CommandConnection.hpp"
#include "al/ui/al_ParameterServer.hpp"

#include "tinc/DataPool.hpp"
#include "tinc/DiskBuffer.hpp"
#include "tinc/ParameterSpace.hpp"
#include "tinc/Processor.hpp"
#include "tinc/TincProtocol.hpp"

namespace tinc {

/**
 * @brief The TincClient class
 *
 * A TincClient connects to a TincServer to share TINC objects.
 */
class TincClient : public al::CommandClient, public TincProtocol {
public:
  TincClient();

  /**
   * @brief start the TINC client
   * @param serverPort
   * @param serverAddr
   * @return true if connection was succesful
   */
  bool start(uint16_t serverPort = 34450,
             const char *serverAddr = "localhost") override;
  /**
   * @brief stop the connection
   *
   * Closes listening thread and cleans up connections.
   *
   * Any state received from the server remains on the client, but any actions
   * will not affect the server and will be overriden if reconnected.
   */
  void stop() override;

  // See documentation on TincProtocol
  bool sendTincMessage(void *msg, al::Socket *dst = nullptr,
                       al::ValueSource *src = nullptr) override;

  void requestParameters();
  void requestProcessors();
  void requestDiskBuffers();
  void requestDataPools();
  void requestParameterSpaces();

  void synchronize();

  void sendMetadata();

  /**
   * @brief Wait for lock, then wait for unlock.
   * @param group group to make the barrier for. 0 is all.
   * @param timeoutsec timeout time im seconds
   * @return true if not timed out
   */
  bool barrier(uint32_t group = 0, float timeoutsec = 0.0) override;

  /**
   * @brief Return latest status reported by server
   */
  Status serverStatus();

  /**
   * @brief return only when server status is STATUS_AVAILABLE
   * @param timeoutsec
   * @return false if timeout instead of STATUS_AVAILABLE
   */
  bool waitForServer(float timeoutsec = 0.0);

  /**
   * @brief send a ping message to the tinc server
   * @return a number that identifies the ping
   *
   * The server will return a pong message with the number recieved.
   */
  uint64_t pingServer();

  /**
   * @brief waitForPong
   * @param pingCode
   * @param timeoutsec
   * @param src Source of pong message (use nullptr for server)
   * @return true if pong was received before timeout
   *
   * This function clears mPongsReceived for src if pong was received before
   * time out.
   */
  bool waitForPong(uint64_t pingCode, float timeoutsec = 30,
                   al::Socket *src = nullptr);

  void setVerbose(bool verbose = true);
  bool verbose() { return TincProtocol::mVerbose; }

protected:
  bool processIncomingMessage(al::Message &message, al::Socket *src) override;
  void processBarrierRequest(al::Socket *src, uint64_t barrierConsecutive);
  void processBarrierUnlock(al::Socket *src, uint64_t barrierConsecutive);

  void processStatusMessage(void *message);
  void processWorkingPathMessage(void *message);

  // FIXME more robust locking unlocking when things go wrong. e.g. missed
  // messages, timeout, etc.
  bool lockLocalSend();
  bool unlockLocalSend();

private:
  // Network barriers
  std::map<uint64_t, al::Socket *> mBarrierRequests;
  std::map<uint64_t, al::Socket *> mBarrierUnlocks;
  std::mutex mBarrierQueuesLock;

  std::mutex mLocalSendLock;

  bool mWaitForServer{false};

  std::string mWorkingPath;

  Status mServerStatus;
  uint64_t mPingCounter{0};
};

} // namespace tinc

#endif // TINCCLIENT_HPP
