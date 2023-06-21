cmake_minimum_required(VERSION 3.17)
project(MatricesGLM)

set(CMAKE_CXX_STANDARD 20)

add_executable(MatricesGLM main.cpp glut_ply.cpp glut_ply.h stb_image.cpp stb_image.h)

target_link_libraries(MatricesGLM -lOpenGL32 -lGLU32 -lfreeGLUT -lglfw3 -lGLEW32)