cmake_minimum_required(VERSION 3.20)

project(GameEngine)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES
	src/Main.cpp
	src/ECS/components/PositionComponent/PositionComponent.cpp
)

add_compile_options(
    -Wall
    -Wextra
	-Wpedantic
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

file(GLOB COMPONENT_DIRS LIST_DIRECTORIES true
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ECS/components/*"
)


target_include_directories(${PROJECT_NAME} PRIVATE
    ${COMPONENT_DIRS}
)

include_directories(
	include
)

