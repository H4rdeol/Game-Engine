/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ECS.hpp
*/

#pragma once

#include <memory>
#include <cassert>
#include <vector>
// ? A templated class or abstract class to easily create mapper

namespace ECS
{
    using EntityId = std::size_t;

    class ECS {
        public:
            ECS(const ECS &) = delete;
            ECS &operator=(const ECS &) = delete;

            static void Init();
            static void Shutdown();

            static ECS &GetInstance();
        private:
            ECS() = default;
            ~ECS() = default;
        private:
            std::vector<EntityId> p_entities;
    };
}
