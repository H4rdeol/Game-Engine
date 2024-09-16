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
    class ECSa {
        public:
            ECSa() = default;
            ~ECSa() = default;
            ECSa(const ECSa &cpy) = delete;
            ECSa &operator=(const ECSa &src) = delete;
            ECSa(ECSa &&src) = delete;
            ECSa &operator=(ECSa &&src) = delete;
    };
}
