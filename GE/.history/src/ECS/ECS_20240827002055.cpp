/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ECS.cpp
*/

#include "ECS.hpp"

namespace ECS
{
    static ECS *instance = nullptr;

    void ECS::Init()
    {
        assert(!instance);

        instance = new ECS();
    }
}
