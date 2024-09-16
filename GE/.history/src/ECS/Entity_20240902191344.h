/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Entity.h
*/

#pragma once

#include "ComponentManager/ComponentManager.hpp"

#include <cstddef>
#include <set>

namespace E {

}

struct Entity {
    std::size_t id;
    std::set<ECS::ComponentsManager::ComponentsType> components;
};
