/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ECS.cpp
*/

#include "ECS.hpp"

namespace ECS
{
    ECS::Scene::Scene()
    {
        entities.reserve()
    }

    void Scene::AddEntity()
    {
        static std::size_t id = 0;

        entities.push_back(id++);
    }

    void Scene::RemoveEntity()
    {
        assert(entities.size() > 0);

        std::swap(entities.back(), entities.front());
        entities.pop_back();
    }
}
