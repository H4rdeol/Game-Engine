/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ECS.hpp
*/

#pragma once

#include <vector>
#include <memory>
#include <cassert>
// ? A templated class or abstract class to easily create mapper

namespace ECS
{
    class ECS {
        public:
            ECS(const ECS &) = delete;
            ECS &operator=(const ECS &) = delete;

            static void Init();
            static void Shutdown();

            static ECS &
    };
}
