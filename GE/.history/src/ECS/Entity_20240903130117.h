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
    struct Entity {
        std::size_t id;
        std::set<std::string> components;
    };
}
