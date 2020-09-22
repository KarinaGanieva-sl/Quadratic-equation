cmake_minimum_required(VERSION 3.17)
project(quadratic_equation C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wfloat-equal")

set(CMAKE_C_STANDARD 99)

add_executable(quadratic_equation quadratic_equation.c tests.c main.c tests.h quadratic_equation.h)
