/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ComponentMapper.cpp
*/

#include "ComponentManager.hpp"


namespace ECS
{
    ComponentsManager::ComponentsManager()
    {
        p_registeredComponents[typeid(PositionsComponents).name()] = std::make_unique<PositionsComponents>();
    }
}
