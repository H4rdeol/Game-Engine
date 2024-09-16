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
            virtual void Initialize() = 0;
            virtual void OnAddedToEntity() = 0;
            virtual void OnRemovedFromEntity() = 0;
            virtual void Update() = 0;
            virtual void DebugRender() = 0;
            virtual void OnEnabled() = 0;
            virtual void OnDisabled() = 0;
    };
}
