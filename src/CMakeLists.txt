# src/CMakeLists.txt

# Define executable and attach source files
add_executable(ProgrammingProject2
  # The entry point and the files for displaying and performing each operation type.
  main.cpp
  setOperations/RepresentationHelper.cpp
  setOperations/Sets.cpp
  setOperations/MultiSets.cpp
  setOperations/FuzzySets.cpp
)

# Compiler warning configuration for cross-platform compiling
if(MSVC)
  target_compile_options(ProgrammingProject2 PRIVATE
        /W4
        /WX
        /permissive-
        /Zc:preprocessor
    )
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(ProgrammingProject2 PRIVATE
        -Wall
        -Wextra
        -Werror
    )
endif()
