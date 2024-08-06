project(Catch2_Reproducer)

cmake_minimum_required(VERSION 3.16.8)

option(BUILD_SHARED_LIBS "Option for testing shared libraries" ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.6.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

include(CTest)
include(Catch)

add_executable(tests test-main.cpp test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2)

catch_discover_tests(tests)
