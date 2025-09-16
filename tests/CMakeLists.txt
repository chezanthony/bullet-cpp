add_executable(bullet_tests
  test_main.cc
  test_dummy.cc
)

target_link_libraries(bullet_tests PRIVATE
  bullet-cpp
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(bullet_tests)
