/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Main.cpp
*/

#include "Application/Application.hpp"
#include "ECS/ECS.hpp"

int main(UNUSED int argc, UNUSED char *argv[])
{
    ECS::ECS::Init();
    App::Application myApp {
        {
            sf::Vector2u(1920, 1080),
            "Test je cho",
            60,
            32
        }
    };

    ECS::ECS::GetInstance().AddEntity();
    ECS::ECS::GetInstance().AddEntity();
    ECS::ECS::GetInstance().AddEntity();


    ECS::ECS::GetInstance().RemoveEntity({1, {}});
    ECS::ECS::GetInstance().PrintEntities();
    myApp.run();
    ECS::ECS::Shutdown();
    return 0;
}
