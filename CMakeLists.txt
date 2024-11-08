cmake_minimum_required(VERSION 3.12)
project(MyProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
add_executable(MyProject
    src/Main.cpp
    src/Application/Application.cpp
    src/ECS/ECS.cpp
    src/Scene/Scene.cpp
    src/ComponentManager/ComponentManager.cpp
    src/ComponentManager/Components.cpp
    src/Systems/Systems.cpp
    src/Systems/Systems.hpp
    include/Interface/ISystems.hpp
    include/Abstract/ASystems.hpp
    include/Abstract/ASystems.cpp
)

target_include_directories(MyProject PUBLIC include/Interface)
target_include_directories(MyProject PUBLIC include/Abstract)
target_include_directories(MyProject PRIVATE src)
target_link_libraries(MyProject PRIVATE sfml-graphics sfml-window sfml-system)