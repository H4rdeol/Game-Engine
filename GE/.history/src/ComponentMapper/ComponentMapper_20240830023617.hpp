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

    class IComponent {
        public:
            virtual ~IComponent() = default;

            template<typename ...T>
            virtual void AddToEntity(const EntityId entity, T... args) = 0;
    };

    struct PositionsComponents: public IComponent {
        void AddToEntity(const EntityId entity, float) override
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
            void AddSpecificComponent(const EntityId entity, PositionsComponents &component, float x, float y);
        private:
            std::map<EntityId, std::vector<std::size_t>> p_componentsIndexes;
    };
}
