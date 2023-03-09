#include "gtest/gtest.h"

#include "tinc/TincClient.hpp"
#include "tinc/TincServer.hpp"

#include "al/system/al_Time.hpp"
using namespace tinc;

TEST(Barrier, SingleBarrier) {
  TincServer tserver;
  EXPECT_TRUE(tserver.start());

  TincClient tclient;
  EXPECT_TRUE(tclient.start());

  std::thread th_server([&]() { EXPECT_TRUE(tserver.barrier()); });
  al::al_sleep(0.1);
  std::thread th_clients([&]() { EXPECT_TRUE(tclient.barrier()); });

  th_server.join();
  th_clients.join();

  tclient.stop();
  tserver.stop();
}

TEST(Barrier, ClientFirst) {
  TincServer tserver;
  EXPECT_TRUE(tserver.start());

  TincClient tclient;
  EXPECT_TRUE(tclient.start());

  std::thread th_clients([&]() { EXPECT_TRUE(tclient.barrier()); });
  al::al_sleep(0.1);
  std::thread th_server([&]() { EXPECT_TRUE(tserver.barrier()); });

  th_server.join();
  th_clients.join();
  tclient.stop();
  tserver.stop();
}

TEST(Barrier, FastTrigger) {
  TincServer tserver;
  EXPECT_TRUE(tserver.start());

  TincClient tclient;
  EXPECT_TRUE(tclient.start());

  //   Multiple quick ones
  for (int i = 0; i < 30; i++) {
    std::thread th_clients2([&]() { EXPECT_TRUE(tclient.barrier()); });
    std::thread th_server2([&]() { EXPECT_TRUE(tserver.barrier()); });

    th_server2.join();
    th_clients2.join();
  }

  for (int i = 0; i < 30; i++) {
    std::thread th_clients2([&]() { EXPECT_TRUE(tserver.barrier()); });
    std::thread th_server2([&]() { EXPECT_TRUE(tclient.barrier()); });

    th_server2.join();
    th_clients2.join();
  }

  tclient.stop();
  tserver.stop();
}

TEST(Barrier, BarrierStack) {
  //  TincServer tserver;
  //  EXPECT_TRUE(tserver.start());

  //  TincClient tclient;
  //  EXPECT_TRUE(tclient.start());

  //  al::al_sleep(0.5);

  //  // Create two barriers on the server
  //  std::thread th_server([&]() { EXPECT_TRUE(tserver.barrier()); });

  //  std::thread th_server2([&]() { EXPECT_TRUE(tserver.barrier()); });

  //  // Should require two barriers on client
  //  std::thread th_client([&]() { EXPECT_TRUE(tclient.barrier()); });

  //  std::thread th_client2([&]() { EXPECT_TRUE(tclient.barrier()); });

  //  th_server.join();
  //  th_client.join();
  //  th_server2.join();
  //  th_client2.join();

  //  tclient.stop();
  //  tserver.stop();
}

TEST(Barrier, MultiClient) {
  // FIXME fix support for multiclient barrier
  //  TincServer tserver;
  //  EXPECT_TRUE(tserver.start());

  //  TincClient tclient;
  //  EXPECT_TRUE(tclient.start());

  //  TincClient tclient2;
  //  EXPECT_TRUE(tclient2.start());

  //  TincClient tclient3;
  //  EXPECT_TRUE(tclient3.start());

  //  TincClient tclient4;
  //  EXPECT_TRUE(tclient4.start());

  //  al::al_sleep(1.0);

  //  //  std::thread th_clients([&]() {
  //  //    tclient.barrier();
  //  //    tclient2.barrier();
  //  //  });
  //  std::thread th_server([&]() { tserver.barrier(); });
  //  std::thread th_clients2([&]() {
  //    tclient3.barrier();
  //    tclient4.barrier();
  //  });

  //  th_server.join();
  //  //  th_clients.join();
  //  th_clients2.join();

  //  tclient.stop();
  //  tclient2.stop();
  //  tclient3.stop();
  //  tclient4.stop();
  //  tserver.stop();
}
