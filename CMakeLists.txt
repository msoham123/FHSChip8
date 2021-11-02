cmake_minimum_required(VERSION 3.20)
project(FHSChip8)

set(CMAKE_CXX_STANDARD 23)

add_executable(FHSChip8 src/main.cpp src/CPU/CPU.cpp src/CPU/CPU.h)
