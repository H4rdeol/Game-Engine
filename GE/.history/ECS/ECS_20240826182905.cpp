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
        entities.push_back(
            static_cast<std::size_t>(PreExistingEntity::Camera)
        );
    }

    void Scene::AddEntity()
    {
        static std::size_t id = static_cast<std::size_t>(
            PreExistingEntity::NbPreExistingEntities);

        entities.push_back(id++);
    }

    void Scene::RemoveEntity()
    {
        assert(entities.size() > 0);

        std::swap(entities.back(), entities.front());
        entities.pop_back();
    }
}
