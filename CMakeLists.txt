cmake_minimum_required(VERSION 3.10)
# CMake 최소 버전 지정. CMake 3.10 이상이어야 이 파일을 해석 가능

project(StringHelperProject)
# 프로젝트 이름 지정

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# C++17 문법 사용 선언

# include 디렉토리 추가 (헤더 경로)
include_directories(include)

# GoogleTest 다운로드 및 설정
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
# 테스트 기능 사용

# 메인 실행 파일 - 파일 경로 주의: src/
add_executable(main_exec
  src/main.cc
  src/string_helper.cc
)

# 테스트 실행 파일 - 파일 경로 주의: test/, src/
add_executable(string_helper_test
  test/string_helper_test.cc
  src/string_helper.cc
)

# GoogleTest 라이브러리 연결
target_link_libraries(string_helper_test gtest_main)

# 테스트 자동 등록
include(GoogleTest)
gtest_discover_tests(string_helper_test)
