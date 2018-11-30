cmake_minimum_required (VERSION 3.12)
project ({{ cookiecutter.kata|lower }})

# C++ 17, and export compile commands for secondary tooling to work well
#
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add Trompeloeil as a CMake subdirectory. Catch! and fff are header-only.
#
add_subdirectory(lib/trompeloeil-32)

# For the sake of form, and to give an idea of the sort of setup you'd
# find in a "real world" project, we're keeping the sources separate,
# and creating a separate archive
#
set (production-sources
    src/{{ cookiecutter.kata }}.cpp)
add_library ({{ cookiecutter.kata|lower }} STATIC ${production-sources})
target_include_directories ({{ cookiecutter.kata|lower }} PRIVATE include)

# The unit tests executable, statically linking the "production" code, and
# the test library dependencies.
#
set (test-sources
    test/test_runner.cpp
    test/{{ cookiecutter.kata }}_test.cpp)
add_executable ({{ cookiecutter.kata|lower }}test ${test-sources})
target_link_libraries ({{ cookiecutter.kata|lower }}test {{ cookiecutter.kata|lower }}
    trompeloeil pthread)
target_include_directories ({{ cookiecutter.kata|lower }}test PRIVATE
    lib/catch-2.5.0
    lib/fff-20181128
    lib/trompeloeil-32	
    include)
