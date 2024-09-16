/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Entity.h
*/

#pragma once

#include <set>

#include "ComponentManager/ComponentManager.hpp"

namespace ECS
{
    

    struct Entity {
        std::size_t id;
        std::set<ComponentsManager::ComponentsType> components;
    };
}
