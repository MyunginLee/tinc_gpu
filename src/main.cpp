#include <iostream>

// for master branch
// #include "al/core.hpp"

// for devel branch
#include "al/app/al_App.hpp"
#include "al/graphics/al_Shapes.hpp"
#include "al/graphics/al_Image.hpp"
#include "al/graphics/al_Texture.hpp"
#include "tinc/ProcessorCpp.hpp"
#include "tinc/ParameterSpace.hpp"
#include "tinc/ProcessorScript.hpp"

#include "al/app/al_App.hpp"
#include "al/graphics/al_Font.hpp"
#include "al/io/al_File.hpp"
#include "al/system/al_Time.hpp"
#include "al/ui/al_ControlGUI.hpp"

  // LD_LIBRARY_PATH=/home/ben/Desktop/Projects/qvxallo/tinc/external/usr/lib/

using namespace al;
using namespace std;
using namespace tinc;
std::string clean_double_to_string(double value);

struct MyApp : App {
  ProcessorScript processor;
  ParameterSpace ps;

  Mesh mesh;
  double phase = 0;
  void initializeComputation() {
    // set local filename here relative to running directory and output
    // directory
    cout << " init python run" << endl;
    processor.setCommand("python");
    processor.setScriptName("src/compute_main.py");
    ps.sweep(processor);

    // processor.setOutputFileNames({"voltage_curve.png"});
    // need to assign processor.registerDoneCallback to load image
    //(should be able to use running/output directory to find file)
    cout << " init python ran" << endl;
  }
  void onInit() override {
    // defineParameterSpace();
    initializeComputation();
    // Sweep the parameter space running 'processor' on every sample
  }

  void onCreate() override {
    addTetrahedron(mesh);
    lens().near(0.1).far(25).fovy(90);
    nav().pos(0, 0, 4);
    nav().quat().fromAxisAngle(0. * M_2PI, 0, 1, 0);
  }

  void onAnimate(double dt) override {
    double period = 10;
    phase += dt / period;
    if (phase >= 1.) phase -= 1.;

  }

  void onDraw(Graphics& g) override {
    g.clear(0, 0, 0);
    g.polygonLine();
    g.pushMatrix();
    g.rotate(phase * 360, 0, 1, 0);
    g.color(1);
    g.draw(mesh);
    g.popMatrix();
  }
};

int main() {
  MyApp app;
  app.dimensions(600, 400);
  app.start();
}


  std::string clean_double_to_string(double value) {
    std::string val_as_string = std::to_string(value);
    auto trimmed = std::unique(val_as_string.begin(), val_as_string.end());
    std::string single_zero(val_as_string.begin(), trimmed);
    if (single_zero.back() == '0') {
      single_zero.pop_back();
    }
    if (single_zero.back() == '.') {
      single_zero.push_back('0');
    }
    return single_zero;
  }