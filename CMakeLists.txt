cmake_minimum_required(VERSION 3.17)
project(OPENGL_GLFW)

set(CMAKE_CXX_STANDARD 20)

add_executable(OPENGL_GLFW main.cpp)

#it will look thru lib for glfw3.dll
target_link_libraries(OPENGL_GLFW -lglew32 -lopengl32 -lglfw3)