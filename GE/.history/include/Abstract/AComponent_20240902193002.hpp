/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** AComponent.cpp
*/

#pragma once

#include <map>

#include "IComponent.hpp"

namespace ECS
{
    class ComponentsManager;

    class AComponent: public IComponent {
        protected:
            std::map<std::size_t, std::size_t> IdToIndex_p;
    };
}
