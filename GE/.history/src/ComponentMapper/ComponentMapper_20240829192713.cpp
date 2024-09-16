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
    void ComponentsMapper::AddComponent(const EntityId entity, C &component)
    {
        //assert(); pas la méthode dans ECS pour gérer le cas où bad EntityID // ? Faire un throw à la place pour être plus doux ?
        // va_list data;

        // va_start(data, component);
        AddSpecificComponent(const EntityId entity, PositionsComponents &component, float x, float y)
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
