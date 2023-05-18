cmake_minimum_required(VERSION 3.25)
project(E1_basico)

set(CMAKE_CXX_STANDARD 17)

add_executable(E1_basico hello_triangle_indexed.cpp glad.c)
target_link_libraries(E1_basico -lOpenGL32 -lGLU32 -lfreeGLUT -lglfw3)

add_executable(E2_ShadersUniform shaders_uniform.cpp glad.c)
target_link_libraries(E2_ShadersUniform -lOpenGL32 -lGLU32 -lfreeGLUT -lglfw3)

add_executable(E3_ShaderClass shader/shaders_class.cpp glad.c)
target_link_libraries(E3_ShaderClass -lOpenGL32 -lGLU32 -lfreeGLUT -lglfw3)

add_executable(E5_Transformations shader/transformations.cpp shader/stb_image.cpp glad.c)
target_link_libraries(E5_Transformations -lOpenGL32 -lGLU32 -lfreeGLUT -lglfw3)
