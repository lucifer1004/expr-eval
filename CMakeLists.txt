cmake_minimum_required(VERSION 3.15)
project(expr_eval)

set(CMAKE_CXX_STANDARD 17)

add_executable(expr_eval main.cc calculator.cc)