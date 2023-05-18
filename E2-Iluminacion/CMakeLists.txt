cmake_minimum_required(VERSION 3.25)
project(E2_Iluminacion)

set(CMAKE_CXX_STANDARD 17)

add_executable(E2_Iluminacion 2.1.basic_lighting_diffuse/basic_lighting_diffuse.cpp glad.c)
target_link_libraries(E2_Iluminacion -lOpenGL32 -lGLU32 -lfreeGLUT -lglfw3)
