/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Components.cpp
*/

#include "Components.hpp"
#include "ECS/Entity.h"

namespace ECS::Components
{
    void PositionsComponents::AddToEntity(const Entity &entity, va_list args, ...)
    {
            va_start(args, args);
            m_positions.push_back(
                std::make_pair(
                    va_arg(args, double),
                    va_arg(args, double)
                )
            );
            va_end(args);
            IdToIndex_p[entity.id] = m_positions.size() - 1;
            entity.components.push_back
    }

    void PositionsComponents::RemoveFromEntity(const Entity &entity)
    {
        std::size_t index = IdToIndex_p[entity.id];

        std::swap(m_positions[index], m_positions.back());
        m_positions.pop_back();
        IdToIndex_p.erase(index);
    }
}
