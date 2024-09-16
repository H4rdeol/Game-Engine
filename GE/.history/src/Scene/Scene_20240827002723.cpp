/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Scene.cpp
*/

#include "Scene.hpp"

namespace ECS
{
    ECS::Scene::Scene()
    {
        _entities.push_back(
            static_cast<std::size_t>(PreExistingEntity::Camera)
        );
    }

    void Scene::AddEntity()
    {
        static std::size_t id = static_cast<std::size_t>(
            PreExistingEntity::NbPreExistingEntities
        );

        _entities.push_back(id++);
    }

    void Scene::RemoveEntity()
    {
        assert(_entities.size() > 0);

        std::swap(_entities.back(), _entities.front());
        _entities.pop_back();
    }
}