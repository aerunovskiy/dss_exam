cmake_minimum_required(VERSION 3.17)
project(dss)

set(CMAKE_CXX_STANDARD 14)

add_executable(dss main.cpp
                   monitor.h
                   br.h)