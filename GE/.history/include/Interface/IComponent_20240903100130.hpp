/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** IComponent.hpp
*/

#pragma once

#include "ECS/Entity.h"

namespace ECS
{
    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual void AddToEntity(const Entity &entity, ...) = 0;
            virtual void RemoveFromEntity(const Entity &entity) = 0;
    };
}
