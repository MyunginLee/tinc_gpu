#include "al/app/al_DistributedApp.hpp"
#include "al/graphics/al_Image.hpp"
#include "al/ui/al_ControlGUI.hpp"

#include "tinc/DiskBufferImage.hpp"
#include "tinc/TincServer.hpp"

using namespace al;
using namespace tinc;

struct TincApp : DistributedApp {

  Parameter param{"param", "", 0.5, 0.0, 1.0};
  DiskBufferImage dataBuffer{"graph", "output.png"};
  TincServer tserv;

  ControlGUI gui;
  Texture graphTex;

  void onInit() override {

    // FIXME expose parameter on TINC server
    parameterServer() << param;

    tserv << dataBuffer;
    tserv.start();
  }

  void onCreate() override {
    gui.init();
    gui << param;

    graphTex.create2D(512, 512);
  }

  void onAnimate(double dt) override {
    if (dataBuffer.newDataAvailable()) {
      if (dataBuffer.get()->array().size() == 0) {
        std::cout << "failed to load image" << std::endl;
      }
      std::cout << "loaded image size: " << dataBuffer.get()->width() << ", "
                << dataBuffer.get()->height() << std::endl;

      graphTex.resize(dataBuffer.get()->width(), dataBuffer.get()->height());
      graphTex.submit(dataBuffer.get()->array().data(), GL_RGBA,
                      GL_UNSIGNED_BYTE);

      graphTex.filter(Texture::LINEAR);
    }
  }

  void onDraw(Graphics &g) override {
    g.clear(0);

    g.pushMatrix();
    g.translate(0, 0, -4);
    g.quad(graphTex, -1, 1, 2, -1.5);
    g.popMatrix();
    gui.draw(g);
  }

  void onExit() override {
    gui.cleanup();
    tserv.stop();
  }
};

int main() {
  TincApp().start();
  return 0;
}
