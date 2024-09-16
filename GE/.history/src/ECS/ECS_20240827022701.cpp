/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ECS.cpp
*/

#include "ECS.hpp"

namespace ECS
{
    ECS::ECSError::ECSError(const std::string &msg) : p_msg(msg)
    {}

    const char* ECS::ECS::ECSError::what() const noexcept
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
        p_entities.push_back(p_entities.size());
    }

    void ECS::RemoveEntity(EntityId entity)
    {
        if (std::find(p_entities.begin(), p_entities.end(), entity) == p_entities.end())
            throw ECSError("Entity n°" "does not exist");
    }
}
