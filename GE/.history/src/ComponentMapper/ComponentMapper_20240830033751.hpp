/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ComponentMapper.hpp
*/

#pragma once

#include "ECS/ECS.hpp"
#include <cstdarg>
#include <map>

namespace ECS
{
    using EntityId = std::size_t;

    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual void AddToEntity(const EntityId entity, ...) = 0;
    };

    struct PositionsComponents: public IComponent {
        void AddToEntity(const EntityId entity, ...) override
        {
            m_positions.push_back(std::make_pair(0, 0));
        }
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

            template<class C, typename ...Args>
            void AddComponent(const EntityId entity, C &component, Args... args);

            template<class C>
            void RemoveComponent(const EntityId entity) const;

            template<class C>
            C &GetComponent(const EntityId entity) const;

            template<class C>
            bool HasComponent(const EntityId entity) const;
        private:
            std::map<EntityId, std::vector<std::size_t>> p_componentsIndexes;
    };
}
