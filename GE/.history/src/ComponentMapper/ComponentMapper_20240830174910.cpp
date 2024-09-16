/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ComponentMapper.cpp
*/

#include "ComponentMapper.hpp"
#include "IComponent.hpp"
#include <cassert>

namespace ECS
{

    void PositionsComponents::AddToEntity(const EntityId entity, ...)
    {
        va_list args;
        va_start(args, entity);
        double x = va_arg(args, double);
        double y = va_arg(args, double);
        m_positions.push_back(std::make_pair(x, y));
        va_end(args);
    }

    template<class C>
    bool ComponentsMapper::HasComponent(const EntityId entity) const
    {
        
    }
}
