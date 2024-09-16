/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ComponentMapper.cpp
*/

#include "ComponentManager.hpp"
#include "Components.hpp"

namespace ECS
{
    ComponentsManager::ComponentsManager()
    {
        p_registeredComponents[typeid(Components::PositionsComponents).name()] = std::make_unique<Components::PositionsComponents>();
        p_registeredComponentsName.push_back(typeid(Components::PositionsComponents).name());
    }
}
