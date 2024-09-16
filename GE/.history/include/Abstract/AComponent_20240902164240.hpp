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
            virtual void AddToMap(const std::size_t id, const std::size_t index);
            virtual void RemoveFromMap(const std::size_t id);
            virtual std::size_t GetIndexFromId(const std::size_t id);
        protected:
            std::map<std::size_t, std::size_t> IdToIndex;
    };
}
