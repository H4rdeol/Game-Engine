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
    void ComponentsMapper::AddComponent(const EntityId entity, C &component)
    {
        //assert(); pas la méthode dans ECS pour gérer le cas o // ? Faire un throw à la place pour être plus doux ?

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
