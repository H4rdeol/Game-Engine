/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ComponentMapper.cpp
*/

#include "ComponentMapper.hpp"

namespace ECS
{
    std::size_t PositionsComponents::AddToEntity(const EntityId entity, ...)
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
            return m_positions.size() - 1;
    }

    void PositionsComponents::RemoveFromEntity(const std::size_t index)
    {
        std::swap(m_positions[index], m_positions.back());
         m_positions.pop_back();
    }

    ComponentsMapper::ComponentsMapper()
    {
        p_registeredComponents[typeid(PositionsComponents).name()] = std::make_unique<PositionsComponents>();
    }

    template<class C>
    bool ComponentsMapper::HasComponent(const EntityId entity) const
    {
        
    }
}
