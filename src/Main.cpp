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
    char name[] = "assets/snook.jpg";

    App::Application myApp {
        {
            sf::Vector2u(1920, 1080),
            "Snook",
            0,
            32
        }
    };
    ECS::ECS::GetInstance().App = &myApp;
    for (int i = 0; i < 100; i++) {
        ECS::ECS::GetInstance().AddEntity();
        ECS::ECS::GetInstance().getComponentsMapper()->AddComponent<ECS::Components::PositionsComponents, double, double>(
                ECS::ECS::GetInstance().getEntity(i),
                ECS::ECS::GetInstance().getComponentsMapper()->GetComponent<ECS::Components::PositionsComponents>(),
                0.0,
                0.0
        );
        ECS::ECS::GetInstance().getComponentsMapper()->AddComponent<ECS::Components::SpriteComponents, char *>(
                ECS::ECS::GetInstance().getEntity(i),
                ECS::ECS::GetInstance().getComponentsMapper()->GetComponent<ECS::Components::SpriteComponents>(),
                name
        );
    }

    myApp.run();
    ECS::ECS::Shutdown();
    return 0;
}
