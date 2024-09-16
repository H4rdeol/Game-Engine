/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ECS.cpp
*/

#include "ECS.hpp"

namespace ECS
{
    void Scene::AddEntity()
    {
        static std::size_t id = 0;

        entities.push_back(id++);
    }

    void Scene::RemoveEntity()
    {
        std::swap
    }
}
