/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ComponentMapper.hpp
*/

#pragma once

#include "ECS/ECS.hpp"
#include <map>

namespace ECS
{
    using EntityId = std::size_t;

    struct PositionsComponents {
        std::vector<std::pair<float, float>> m_positions;
    };

    class ComponentsMapper {
        public:
            ComponentsMapper() = default;
            ~ComponentsMapper() = default;

            enum class ComponentsType {
                Nothing = -1,
                Position,
                NbComponents
            };

            template<class C>
            void AddComponent(const EntityId entity, C &component);

            template<class C>
            void RemoveComponent(const EntityId entity) const;

            template<class C>
            C &GetComponent(const EntityId entity) const;

            template<class C>
            bool HasComponent(const EntityId entity) const;
        private:
            void 
        private:
            std::map<EntityId, std::vector<std::size_t>> p_componentsIndexes;
    };
}
