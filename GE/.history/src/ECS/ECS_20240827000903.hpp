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
            ECS() = default;
            ~ECS() = default;
            ECS(const ECS &cpy) = delete;
            ECS &operator=(const ECS &src) = delete;
            ECS(ECS &&src) = delete;
            ECS &operator=(ECS &&src) = delete;
    };
}
