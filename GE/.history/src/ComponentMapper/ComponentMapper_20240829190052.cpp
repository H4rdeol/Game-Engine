/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ComponentMapper.cpp
*/

#include "ComponentMapper.hpp"

namespace ECS
{
    template<class C>
    void ComponentsMapper::AddComponent(const EntityId entity, C &component) const
    {
        if (p_componentsIndexes.contains(entity)) {
            p_componentsIndexes.at(entity = component;
        }
    }

    template<class C>
    void ComponentsMapper::RemoveComponent(const EntityId entity) const
    {
        
    }

    template<class C>
    C& ComponentsMapper::GetComponent(const EntityId entity) const
    {
        
    }

    template<class C>
    bool ComponentsMapper::HasComponent(const EntityId entity) const
    {
        
    }
}
