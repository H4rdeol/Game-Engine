/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Components.cpp
*/

#include "Components.hpp"

namespace ECS::Components
{
    void PositionsComponents::AddToEntity(const Entity entity, ...)
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
            IdToIndex_p[entity.id] = m_positions.size() - 1;
    }

    void PositionsComponents::RemoveFromEntity(const Entity entity)
    {
        std::size_t index = IdToIndex_p[entity.id];

        std::swap(m_positions[index], m_positions.back());
        m_positions.pop_back();
        IdToIndex_p.erase(index);
    }
}
