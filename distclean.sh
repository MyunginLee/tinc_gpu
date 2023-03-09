#!/bin/bash

rm -rf tinc/build

# currently not purging bin directory in case you need dynamic libraries or other config files with the binary
# rm -rf bin