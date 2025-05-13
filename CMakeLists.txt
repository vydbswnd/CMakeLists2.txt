cmake_minimum_required(VERSION 3.10)
project(StringHelperProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# GoogleTest 다운로드 및 설정
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# 메인 실행 파일
add_executable(main_exec main.cc string_helper.cc)

# 테스트 실행 파일
add_executable(string_helper_test string_helper_test.cc string_helper.cc)
target_link_libraries(string_helper_test gtest_main)

include(GoogleTest)
gtest_discover_tests(string_helper_test)
