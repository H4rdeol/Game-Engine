/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ECS.cpp
*/

#include "ECS.hpp"

namespace ECS
{
    static ECS *s_instance = nullptr;

    void ECS::Init()
    {
        assert(!s_instance);

        s_instance = new ECS();
    }

    void ECS::Shutdown()
    {
        assert(s_instance);

        delete s_instance;
        s_instance = nullptr;
    }

    ECS &ECS::GetInstance()
    {
        assert(s_instance);

        return *s_instance;
    }
}
