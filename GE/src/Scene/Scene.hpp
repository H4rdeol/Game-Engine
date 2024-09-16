/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Scene.hpp
*/

#pragma once

#include <cassert>

namespace ECS
{
    class Scene {
        public:
            enum class PreExistingEntity: std::size_t {
                Camera = 0,
                NbPreExistingEntities
            };

            explicit Scene();
            ~Scene() = default;
            void AddEntity();
            void RemoveEntity();
    };
}
