cmake_minimum_required(VERSION 3.10)
project(MyCPPProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

# Add the "Array.cpp" as a separate executable
#add_executable(Array Array.cpp)

# Add subdirectories for other modules
add_subdirectory(C++17/Inline)