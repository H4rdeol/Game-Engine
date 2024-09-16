/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Components.cpp
*/

#include "Components.hpp"
#include "ECS/Entity.h"

#include <typeinfo>

namespace ECS::Components
{
    void PositionsComponents::AddToEntity(Entity &entity, va_list args, ...)
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
            entity.componentsName.insert(typeid(PositionsComponents).name());
    }

    void PositionsComponents::RemoveFromEntity(Entity &entity)
    {
        std::size_t index = IdToIndex_p[entity.id];

        std::swap(m_positions[index], m_positions.back());
        m_positions.pop_back();
        entity.components.erase(ComponentsType::Position);
        IdToIndex_p.erase(index);
    }
}
