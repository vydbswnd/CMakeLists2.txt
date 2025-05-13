cmake_minimum_required(VERSION 3.10)
# CMake 최소 버전 지정. CM맏 3.10 이상이어야 이 파일을 해석가능.

project(StringHelperProject)
#프로젝트 이름을 지정, 나중에 변수 사용할 때 이 이름을 사용

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#c++17 문법을 쓴다고 명시.
#c++17 안 되면 에러 내고 중단하라는 의미

# GoogleTest 다운로드 및 설정
include(FetchContent)
#외부 라이브러리를 쉽게 가져오도록 도와주는 모듈을 불러옴.

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
# google test를 선언. URL 지정한 압축 파일을 받아서 빌드에 쓰겠다는 뜻.

FetchContent_MakeAvailable(googletest)
#실제로 다운로드해서 CMake 프로젝트에 포함시킴.

enable_testing()
#CMake에서 테스트 기능을 사용할 수 있도록 설정. (gtest 쓰려면 필요함)

# 메인 실행 파일
add_executable(main_exec main.cc string_helper.cc)
#

# 테스트 실행 파일
add_executable(string_helper_test string_helper_test.cc string_helper.cc)
target_link_libraries(string_helper_test gtest_main)
#

include(GoogleTest)
#

gtest_discover_tests(string_helper_test)
#
