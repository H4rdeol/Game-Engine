/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ComponentMapper.cpp
*/

#include "ComponentMapper.hpp"
#include <cstdarg>

namespace ECS
{
    template<class C, typename ...Args>
    void ComponentsMapper::AddComponent(const EntityId entity, C &component, Args... args)
    {
        //assert(); pas la méthode dans ECS pour gérer le cas où bad EntityID // ? Faire un throw à la place pour être plus doux ?

        AddSpecificComponent(entity, component, args...);
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
    
    void ComponentsMapper::AddSpecificComponent(const EntityId entity, PositionsComponents &component, float x, float y)
    {
        //
        p_componentsIndexes[entity].push_back(component.m_positions.size());
        component.m_positions.push_back(std::make_pair(x, y));
    }
}
