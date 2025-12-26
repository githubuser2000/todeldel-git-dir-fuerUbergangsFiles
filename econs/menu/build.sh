#!/bin/sh
#cmake --build build --config Release --target all -- -j$(nproc)
cd ~/myRepos/econs/menu/
rm -rf build/*;cd build && cmake .. && cmake --build . && cd - && bin/menu
