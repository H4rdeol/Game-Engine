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

    void ECS::Shutdown()
    {
        assert(instance);

        delete instance;
        instance = nullptr;
    }

    ECS &ECS::GetInstance()
    {
        assert(instance);

        return *instance;
    }
}
