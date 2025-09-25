add_executable(bullet_tests
  test_main.cc
  test_dummy.cc
  event-test.cc
  event-manager-test.cc
)

target_link_libraries(bullet_tests 
  PRIVATE
    bullet-cpp
    GTest::gtest_main
    GTest::gmock
)

target_include_directories(bullet_tests
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

include(GoogleTest)
gtest_discover_tests(bullet_tests)
