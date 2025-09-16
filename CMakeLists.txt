cmake_minimum_required(VERSION 3.15)

include(cmake/version.cmake)

project(
  bullet-cpp
  VERSION ${BULLET_CPP_VERSION_STRING}
  DESCRIPTION "A bare-bones event loop library"
  LANGUAGES CXX
)

  # VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}

message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "Description: ${PROJECT_DESCRIPTION}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(
  bullet-cpp-version.h.in
  bullet-cpp-version.h
  @ONLY
)

add_subdirectory(event-loops)

include(cmake/dependencies.cmake)

enable_testing()
add_subdirectory(tests)
