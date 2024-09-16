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
        static_assert(entities.size() > 0, "No entity to remove")
        std::swap(entities.back(), entities.front());
        entities.pop_back();
    }
}
