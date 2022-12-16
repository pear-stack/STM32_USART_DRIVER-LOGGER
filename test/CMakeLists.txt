cmake_minimum_required(VERSION 3.14)

set(CMAKE_C_STANDARD                99)
set(CMAKE_C_STANDARD_REQUIRED       ON)
set(CMAKE_C_EXTENSIONS              ON)
set(CMAKE_CXX_STANDARD              11)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS            ON)

project(STM32_UART_LOGGER_TEST)
enable_language(C CXX ASM)

enable_testing()

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_library(AD9833 ../src/UART_driver.c)
include_directories(../inc)

add_executable(UART_test main.cpp UART_driver_test.cpp)

target_link_libraries(UART_test
PRIVATE
  GTest::GTest
  AD9833)

enable_testing()

add_test(NAME UART_test
        COMMAND UART_test          
) 
include(GoogleTest)

gtest_discover_tests(UART_test)