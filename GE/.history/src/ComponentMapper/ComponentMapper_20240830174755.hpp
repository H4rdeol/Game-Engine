/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ComponentMapper.hpp
*/

#pragma once

#include <cstdarg>
#include <map>

#include "ECS/ECS.hpp"
#include "IComponent.hpp"

namespace ECS
{
    using EntityId = std::size_t;

    struct PositionsComponents: public IComponent {
        void AddToEntity(const EntityId entity, ...) override
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
        }
        std::vector<std::pair<double, double>> m_positions;
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
            void AddComponent(const EntityId entity, C &component, Args... args)
            {
                //assert(); pas la méthode dans ECS pour gérer le cas où bad EntityID // ? Faire un throw à la place pour être plus doux ?

                // assert(dynamic_cast<IComponent>(component));
                component.AddToEntity(entity, args...);
            }

            template<class C>
            void RemoveComponent(const EntityId entity) const;


            template<class C>
            bool HasComponent(const EntityId entity) const;
        private:
            std::map<EntityId, std::vector<std::size_t>> p_componentsIndexes;
    };
}
