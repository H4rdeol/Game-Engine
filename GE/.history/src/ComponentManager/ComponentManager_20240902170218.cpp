/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ComponentMapper.cpp
*/

#include "ComponentManager.hpp"

namespace ECS
{
    void PositionsComponents::AddToEntity(const EntityId entity, ...)
    {
            va_list args;

            va_start(args, entity);
            m_positions.push_back(
                std::make_pair(
                    va_arg(args, double),
                    va_arg(args, double)
                )
            );
            va_end(args);
            IdToIndex_p[entity] = m_positions.size() - 1;
    }

    void PositionsComponents::RemoveFromEntity(const std::size_t entityId)
    {
        std::size_t index = IdToIndex_p[entityId];

        std::swap(m_positions[index], m_positions.back());
        m_positions.pop_back();
        IdToIndex_p.erase(index);
    }

    ComponentsManager::ComponentsManager()
    {
        p_registeredComponents[typeid(PositionsComponents).name()] = std::make_unique<PositionsComponents>();
    }
}
