/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** IComponent.hpp
*/

#pragma once

namespace ECS
{
    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual void initialize() = 0;
            virtual void onAddedToEntity() = 0;
            virtual void onRemovedFromEntity() = 0;
            virtual void update() = 0;
            virtual void debugRender() = 0;
            virtual void onEnabled() = 0;
            virtual void onDisabled() = 0;
    };
}