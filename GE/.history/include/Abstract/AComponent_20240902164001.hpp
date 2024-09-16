/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** AComponent.cpp
*/

#pragma once

#include <cstddef>
#include <map>

#include "IComponent.hpp"

namespace ECS
{
    class AComponent : public IComponent {
        public:
            void AddToMap();
            void RemoveFromMap();
            std::s
        protected:
            std::map<std::size_t, std::size_t> IdToIndex;
    };
}
