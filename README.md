# tinc-playground

*No longer supported or recommended*

Quick way to build tinc applications. Contains tutorials and cookbook examples.

Developed by:

AlloSphere Research Group

University of California, Santa Barbara

# Installation

## Dependencies

Terminal to run bash
git
cmake version 3.0 or higher

## Setup
On a bash shell:

    ./init.sh

## Building and running applications

The tinc playground provides basic facilties for building and debugging 
single file applications. On a bash shell on Windows, Linux and OS X do:

    ./run.sh path/to/file.cpp

This will build tinc, allolib, and create an executable for the file.cpp called 'file' inside the '''path/to/bin''' directory. It will then run the application.

You can add a file called '''flags.cmake''' in the '''path/to/''' directory which will be added to the build scripts. Here you can add dependencies, include directories, linking and anything else that cmake could be used for.

For more complex projects follow the template provided in tinc-template
[https://github.com/AlloSphere-Research-Group/tinc-template](). This requires 
some knowledge of Cmake but allows more complex workflows and multifile
applications or multiple target binaries.
