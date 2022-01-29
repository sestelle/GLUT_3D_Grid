cmake_minimum_required(VERSION 3.20)
project(GLUT_3D_Grid)

set(CMAKE_CXX_STANDARD 14)

add_executable(GLUT_3D_Grid main.cpp Grid/Grid.cpp Grid/Grid.h Grid/readFile.cpp Grid/minAndMax.cpp Grid/structs.h Grid/onRender.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(GLUT_3D_Grid ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})