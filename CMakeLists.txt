cmake_minimum_required(VERSION 3.0)

project(opengl-game C CXX)

find_package(SDL2 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)
find_library(SDL2_IMAGE_LIB SDL2_image REQUIRED)

file(GLOB sources src/*cpp)
file(GLOB headers src/*.hpp)

add_executable(${PROJECT_NAME} ${headers} ${sources})

target_link_libraries(${PROJECT_NAME} PRIVATE 
    SDL2::SDL2 
    SDL2::SDL2main 
    ${SDL2_IMAGE_LIB} 
    GLEW::GLEW 
    glm
	opengl32
)
