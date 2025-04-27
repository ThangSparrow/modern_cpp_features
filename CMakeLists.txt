cmake_minimum_required(VERSION 3.10)
project(ModernCppFeatures)

enable_testing()

# Set the C++ standard to 11 (or 14/17 if preferred)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectory containing code
add_subdirectory(src)
