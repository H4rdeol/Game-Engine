/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Scene.cpp
*/

// #include "Scene.hpp"

namespace ECS
{
    ECS::Scene::Scene()
    {
        p_entities.push_back(
            static_cast<std::size_t>(PreExistingEntity::Camera)
        );
    }

    void Scene::AddEntity()
    {
        static std::size_t id = static_cast<std::size_t>(
            PreExistingEntity::NbPreExistingEntities
        );

        p_entities.push_back(id++);
    }

    void Scene::RemoveEntity()
    {
        assert(p_entities.size() > 0);

        std::swap(p_entities.back(), p_entities.front());
        p_entities.pop_back();
    }
}
