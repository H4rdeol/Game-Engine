/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Main.cpp
*/

#include "Application/Application.hpp"
#include "ECS/ECS.hpp"
#include "ComponentManager/Components.hpp"
#include "ComponentManager/ComponentManager.hpp"

int main(UNUSED int argc, UNUSED char *argv[])
{
    ECS::ECS::Init();
    ECS::Components::PositionsComponents give_me_a_name;
    ECS::Components::SpriteComponents give_me_a_name2;
    char name[] = "assets/snook.jpg";

    App::Application myApp {
        {
            sf::Vector2u(1920, 1080),
            "Test je cho",
            60,
            32
        }
    };

    ECS::ECS::GetInstance().AddEntity();
    ECS::ECS::GetInstance().getComponentsMapper()->AddComponent<ECS::Components::PositionsComponents, double, double>(
        ECS::ECS::GetInstance().getEntity(0),
        give_me_a_name,
        960.0,
        540.0
    );
    ECS::ECS::GetInstance().getComponentsMapper()->AddComponent<ECS::Components::SpriteComponents, char *>(
            ECS::ECS::GetInstance().getEntity(0),
            give_me_a_name2,
            name
    );




    ECS::ECS::GetInstance().RemoveEntity(0);
    myApp.run();
    ECS::ECS::Shutdown();
    return 0;
}
