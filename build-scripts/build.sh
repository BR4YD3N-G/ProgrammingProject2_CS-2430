#!/bin/bash

# Build the executable with cmake
echo "Compiling..."
cmake -G Ninja -B build
cmake --build ./build
