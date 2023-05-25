cmake_minimum_required(VERSION 3.25)
project(E3_Objetos)

set(CMAKE_CXX_STANDARD 17)

add_executable(E3_Objetos main.cpp glad.c glut_ply.cpp Objeto.cpp)

target_link_libraries(E3_Objetos -lOpenGL32 -lGLU32 -lfreeGLUT -lglfw3)