#!/bin/bash

SRC_DIR="src"
BUILD_DIR="build"
CXX="g++"
STD="-std=c++14"
USE_BUILD_DIR=true



# Find all .cpp files in the src directory
find "$SRC_DIR" -name "*.cpp" | while read cpp_file; do
    # Get base filename (e.g., without_auto.cpp -> without_auto)
    filename=$(basename "$cpp_file" .cpp)

    # (Optional) replicate folder structure in build/
    relative_path="${cpp_file#$SRC_DIR/}"
    if [ "$USE_BUILD_DIR" = true ]; then
        # Create build directory if it doesn't exist
        mkdir -p "$BUILD_DIR"
        output_path="$BUILD_DIR/${relative_path%.cpp}"
    else
        output_path="$SRC_DIR/${relative_path%.cpp}"
    fi

    # Create subdirectories in build folder if needed
    mkdir -p "$(dirname "$output_path")"

    # Compile
    echo "Compiling $cpp_file -> $output_path"
    $CXX $STD "$cpp_file" -o "$output_path"
done