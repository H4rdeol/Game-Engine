/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ComponentMapper.hpp
*/

#pragma once

#include <cstdarg>
#include <memory>
#include <unordered_map>
#include <cassert>

#include "ECS/ECS.hpp"
#include "IComponent.hpp"

namespace ECS
{
    using EntityId = std::size_t;

    class PositionsComponents: public IComponent {
        public:
            PositionsComponents() = default;
            ~PositionsComponents() = default;

            std::size_t AddToEntity(const EntityId entity, ...) override;
        private:
            std::vector<std::pair<double, double>> m_positions;
    };

    class ComponentsMapper {
        public:
            ComponentsMapper();
            ~ComponentsMapper() = default;

            enum class ComponentsType {
                Nothing = -1,
                Position,
                NbComponents
            };

            template<class C, typename ...Args>
            void AddComponent(const EntityId entity, C &component, Args... args)
            {
                static_assert(expression, );

                // assert(dynamic_cast<IComponent>(component));
                std::size_t index = component.AddToEntity(entity, args...);

                if (p_componentsIndexes.contains(entity)) {
                    p_componentsIndexes[entity]
                        [(std::size_t)ComponentsType::Position] = (int)index;
                } else {
                    p_componentsIndexes[entity].reserve(
                        (std::size_t)ComponentsType::NbComponents);
                    for (std::size_t i = 0; i < (std::size_t)ComponentsType::NbComponents; i++)
                        p_componentsIndexes[entity].push_back(-1);
                    p_componentsIndexes[entity]
                        [(std::size_t)ComponentsType::Position] = (int)index;
                }
            }

            template<class C>
            void RemoveComponent(const EntityId entity) const
            {
                int index = p_componentsIndexes.at(entity)
                    [(std::size_t)ComponentsType::Position];

                if (index == -1)
                    return;
                for (auto &component : p_registeredComponents) {
                    if (typeid(C).name() == component.first) {
                        
                    }
                }
            }

            template<class C>
            bool HasComponent(const EntityId entity) const;
        private:
            std::unordered_map<EntityId, std::vector<int>> p_componentsIndexes;
            std::unordered_map<std::string, std::unique_ptr<IComponent>> p_registeredComponents;
    };
}
