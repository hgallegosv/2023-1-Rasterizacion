cmake_minimum_required(VERSION 3.25)
project(E1_basico)

set(CMAKE_CXX_STANDARD 17)

add_executable(E1_basico hello_triangle.cpp glad.c)
target_link_libraries(E1_basico -lOpenGL32 -lGLU32 -lfreeGLUT -lglfw3)