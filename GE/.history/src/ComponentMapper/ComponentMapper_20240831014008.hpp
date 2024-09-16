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

    struct PositionsComponents: public IComponent {
        std::size_t AddToEntity(const EntityId entity, ...) override;
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
                //assert(); pas la méthode dans ECS pour gérer le cas où bad EntityID // ? Faire un throw à la place pour être plus doux ?

                // assert(dynamic_cast<IComponent>(component));
                std::size_t index = component.AddToEntity(entity, args...);
                if (p_componentsIndexes.contains(entity)) {
                    p_componentsIndexes[entity]
                        [static_cast<std::size_t>(ComponentsType::Position)] = index;
                } else {
                    p_
                }
            }

            template<class C>
            void RemoveComponent(const EntityId entity) const
            {
                
            }

            template<class C>
            bool HasComponent(const EntityId entity) const;
        private:
            std::unordered_map<EntityId, std::vector<std::size_t>> p_componentsIndexes;
            std::unordered_map<std::string, std::unique_ptr<IComponent>> p_registeredComponents;
    };
}
