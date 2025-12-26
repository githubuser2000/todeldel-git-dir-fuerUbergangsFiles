#!/bin/sh
cd build
pwd
rm -rf
cmake ..
cmake --build .
cd ..
cd bin
