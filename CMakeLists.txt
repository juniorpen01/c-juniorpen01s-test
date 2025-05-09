cmake_minimum_required(VERSION 3.25.1)
project(
  Juniorpen01sTest
  VERSION 0.1.0
  DESCRIPTION "juniorpen01's C/C++ Testing Framework"
  LANGUAGES C)

add_executable(vector_test tests/vector_test.c)
target_include_directories(vector_test
                           PRIVATE /${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_compile_options(
  vector_test
  PRIVATE $<$<C_COMPILER_ID:GNU>:-Wall
          -Wextra
          -Wpedantic
          -Werror>
          $<$<C_COMPILER_ID:Clang,AppleClang>:-Weverything
          -Werror>
          $<$<C_COMPILER_ID:MSVC>:/W4
          /WX
          /permissive->)
