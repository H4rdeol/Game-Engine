/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Entity.h
*/

#pragma once

#include <set>

namespace ECS
{
    enum class ComponentsType {
        Nothing = -1,
        Position,
        NbComponents
    };

    struct Entity {
        std::size_t id;
        std::set<::ComponentsType> components;
    };
}
