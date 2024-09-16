/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** IComponent.hpp
*/

#pragma once

#include <cstddef>

namespace ECS
{
    using EntityId = std::size_t;

    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual std::size_t AddToEntity(const EntityId entity, ...) = 0;
            virtual void RemoveFromEntity(const std::size_t) = 0;
    };
}
