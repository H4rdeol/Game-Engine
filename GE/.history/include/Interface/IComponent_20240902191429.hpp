/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** IComponent.hpp
*/

#pragma once

#include ""
#include <cstddef>

namespace ECS
{
    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual void AddToEntity(const EntityId entity, ...) = 0;
            virtual void RemoveFromEntity(const std::size_t) = 0;
    };
}
