#!/bin/bash

(	
  LD_LIBRARY_PATH=/home/ben/Desktop/Projects/qvxallo/tinc/external/usr/lib/
  mkdir -p build
  cd build
  mkdir -p release
  cd release
  cmake -DCMAKE_BUILD_TYPE=Release -Wno-deprecated -DBUILD_EXAMPLES=0 ../..
)

# # Configure debug build
# (
#   mkdir -p build
#   cd build
#   mkdir -p debug
#   cd debug
#   cmake -DCMAKE_BUILD_TYPE=Debug -Wno-deprecated -DBUILD_EXAMPLES=0 ../..
# )

