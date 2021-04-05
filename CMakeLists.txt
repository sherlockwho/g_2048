cmake_minimum_required(VERSION 3.16)
project(g_2048)

set(CMAKE_CXX_STANDARD 17)

add_executable(g_2048 main.cpp Game.cpp Game.h Player.cpp Player.h)