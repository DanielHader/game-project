cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 20)

set(PROJECT_NAME Game)

project(${PROJECT_NAME} VERSION 0.0.1)

set(SOURCES
  src/main.cpp 
  src/game.cpp
  src/input.cpp
  src/math/affine_transform.cpp
  src/graphics/shader.cpp
  include/game.hpp
  include/input.hpp
  include/graphics/shader.hpp
  include/math/affine_transform.hpp
  )

find_package(glm CONFIG REQUIRED)

find_package(OpenGL REQUIRED COMPONENTS OpenGL)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

find_package(OpenGL)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} glm::glm ${SDL2_LIBRARIES} ${GLEW_LIBRARIES} OpenGL::GL)
