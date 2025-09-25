add_library(bullet-cpp)

target_sources(bullet-cpp
  PRIVATE
    src/oop.cpp
    src/event.cpp
    src/event-manager.cpp
)

target_include_directories(bullet-cpp
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}
)
