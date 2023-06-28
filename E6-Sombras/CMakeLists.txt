cmake_minimum_required(VERSION 3.25)
project(E6_Sombras)

set(CMAKE_CXX_STANDARD 17)

add_executable(E6_Sombras shadow_mapping_base.cpp glad.c stb_image.cpp shader.h)

target_link_libraries(E6_Sombras -lOpenGL32 -lGLU32 -lfreeGLUT -lglfw3)