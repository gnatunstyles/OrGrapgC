cmake_minimum_required(VERSION 3.14)
project(lab5 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab5 main.c myFun.c myFun.h test/tests.c test/tests.h)