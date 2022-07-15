# ProjectEuler - Solutions to ProjectEuler problems
#
# Written in 2022 by Michael Rodriguez <mike@kaichiuchi.dev>
#
# To the extent possible under law, the author(s) have dedicated all copyright
# and related and neighboring rights to this software to the public domain
# worldwide. This software is distributed without any warranty.
#
# You should have received a copy of the CC0 Public Domain Dedication along with
# this software. If not, see
# <http://creativecommons.org/publicdomain/zero/1.0/>.

# Build system structure is heavily influenced by
# https://cliutils.gitlab.io/modern-cmake/.

cmake_minimum_required(VERSION 3.7...3.23)

if (${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(ProjectEuler
        VERSION 1.0.0.0
        DESCRIPTION "ProjectEuler problem solutions"
        HOMEPAGE_URL "https://github.com/kaichiuchi/ProjectEuler"
        LANGUAGES CXX)

# Set the CMake module path.
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# Enforce out-of-source builds.
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)

if (EXISTS "${LOC_PATH}")
  message(FATAL_ERROR "You cannot build in a source directory (or any directo"
                      "ry with a CMakeLists.txt file). Please make a build su"
                      "bdirectory. Feel free to remove CMakeCache.txt and CMa"
                      "keFiles.")
endif ()

# If a build type has not been defined, we set the build type here.
#
# For development versions, this should be set to Debug. For all other versions,
# this should be set to RelWithDebInfo.
#
# This only matters for single-target generators, and has no effect on
# multi-target generators.
#
# https://www.kitware.com/cmake-and-the-default-build-type/
set(MARIE_DEFAULT_BUILD_TYPE "Debug")

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${MARIE_DEFAULT_BUILD_TYPE}'"
          "as none was specified.")
  set(CMAKE_BUILD_TYPE "${MARIE_DEFAULT_BUILD_TYPE}" CACHE
          STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
          "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif ()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

enable_testing()

find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)

include(cmake/configure_target.cmake)

add_subdirectory(src)