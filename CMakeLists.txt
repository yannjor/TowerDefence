# CMake >= 3.0 is required
cmake_minimum_required(VERSION 3.0)

# Set the project name
project(tower-defence)

# Define the output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)
set(WITH_WARNINGS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb")

# Disable in-source builds
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# Set macro directory
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/macros")

# Include the macros to use
include(auto_collect)
include(check_platform)

# Find the SFML libraries
find_package(SFML 2.4 REQUIRED audio graphics window system)

# Add dependencies
add_subdirectory(deps)

# Add core sources
add_subdirectory(src)