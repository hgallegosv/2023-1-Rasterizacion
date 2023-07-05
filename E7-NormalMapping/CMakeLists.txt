cmake_minimum_required(VERSION 3.25)
project(E7_NormalMapping)

set(CMAKE_CXX_STANDARD 17)

add_executable(E7_NormalMapping normal_mapping.cpp glad.c stb_image.cpp shader.h)

target_link_libraries(E7_NormalMapping -lOpenGL32 -lGLU32 -lfreeGLUT -lglfw3)
