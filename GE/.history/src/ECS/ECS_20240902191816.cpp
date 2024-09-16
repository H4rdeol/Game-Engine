/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ECS.cpp
*/

#include "ECS.hpp"
#include "ComponentManager/ComponentManager.hpp"

#include <iostream>

namespace ECS
{
    ECS::ECSError::ECSError(const std::string &msg) : p_msg(msg)
    {}

    const char* ECS::ECSError::what() const noexcept
    {
        return p_msg.c_str();
    }

    static ECS *s_Instance = nullptr;

    void ECS::Init()
    {
        assert(!s_Instance);

        s_Instance = new ECS();
    }

    void ECS::Shutdown()
    {
        assert(s_Instance);

        delete s_Instance;
        s_Instance = nullptr;
    }

    ECS &ECS::GetInstance()
    {
        assert(s_Instance);

        return *s_Instance;
    }

    void ECS::AddEntity()
    {
        p_entities.push_back({
            .id=p_entities.size(),
            .components={});
    }

    void ECS::RemoveEntity(Entity entity)
    {
        auto it = std::find(p_entities.begin(), p_entities.end(), entity);

        if (it == p_entities.end())
            throw ECSError("Entity with ID = " + std::to_string(entity) + " does not exist");
        p_entities.erase(it);
    }

    bool ECS::HasEntity(Entity entity) const
    {
        return std::find(p_entities.begin(), p_entities.end(), entity) != p_entities.end();
    }

    void ECS::PrintEntities() const
    {
        for (const auto &entity : p_entities)
            std::cout << entity << std::endl;
    }
}
