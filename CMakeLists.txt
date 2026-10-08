# Project root CMakeLists.txt for ProgrammingProject2_CS-2430
# Link to cmake website/documentation: "https://cmake.org"
cmake_minimum_required(VERSION 4.0) # Use CMake 4.0 or later

# Define Project Metadata
project(
  "Programming Project 2"
  VERSION 1.0
  DESCRIPTION "Programming Project 2 - CS 2430"
  HOMEPAGE_URL "https://github.com/BR4YD3N-G/ProgrammingProject2_CS-2430"
  LANGUAGES CXX
  )

# Global Configuration
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Ensures strict compliance across OS platforms

# Enable CTest infrastructure
enable_testing()


# Required for Clang-Tidy to map include headers properly on Linux/macOS
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Setup Clang-Tidy
#find_program(CLANG_TIDY_EXE NAMES clang-tidy)
#if(CLANG_TIDY_EXE)
#  message(STATUS "Clang-Tidy found: ${CLANG_TIDY_EXE}")
#
#  # Enable Clang-Tidy globally for all targets defined down the line
#  # Looks for a .clang-tidy configuration file in the project root
#  set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY_EXE})
#else()
#  message(WARNING "Clang-Tidy not found! Static analysis will be skipped.")
#endif()

# Process the source directory
add_subdirectory(src)
add_subdirectory(tests)
