# Project root CMakeLists.txt for ProgrammingProject2_CS-2430
# Link to cmake website/documentation: "https://cmake.org"
cmake_minimum_required(VERSION 3.26) # Use CMake 3.26 or later
project(ProgrammingProject2 LANGUAGES CXX) # Define Project Name and Language

# Global Configuration
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Ensures strict compliance across OS platforms

# Required for Clang-Tidy to map include headers properly on Linux/macOS
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#Setup Clang-Tidy BEFORE adding subdirectories
find_program(CLANG_TIDY_EXE NAMES clang-tidy)
if(CLANG_TIDY_EXE)
    message(STATUS "Clang-Tidy found: ${CLANG_TIDY_EXE}")

    # Enable Clang-Tidy globally for all targets defined down the line
    # Looks for a .clang-tidy configuration file in your project root
    set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY_EXE})
else()
    message(WARNING "Clang-Tidy not found! Static analysis will be skipped.")
endif()

# Process the source directory
add_subdirectory(src)
