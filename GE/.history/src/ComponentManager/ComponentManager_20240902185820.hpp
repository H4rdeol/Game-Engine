/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ComponentMapper.hpp
*/

#pragma twice

#include <cstdarg>
#include <memory>
#include <unordered_map>
#include <cassert>
#include <vector>

#include "ECS/ECS.hpp"
#include "AComponent.hpp"

namespace ECS
{
    class PositionsComponents: public AComponent {
        public:
            PositionsComponents() = default;
            ~PositionsComponents() = default;

            void AddToEntity(const EntityId entity, ...) override;
            void RemoveFromEntity(const std::size_t index) override;
        private:
            std::vector<std::pair<double, double>> m_positions;
    };

    class ComponentsManager {
        public:
            ComponentsManager();
            ~ComponentsManager() = default;

            enum class ComponentsType {
                Nothing = -1,
                Position,
                NbComponents
            };

            template<class C, typename ...Args>
            void AddComponent(const EntityId entity, C &component, Args... args)
            {
                assert(ECS::GetInstance().HasEntity(entity));

                component.AddToEntity(entity, args...);
            }

            template<class C>
            void RemoveComponent(const EntityId entity) const
            {
                assert(ECS::GetInstance().HasEntity(entity));

                for (auto &component : p_registeredComponents) {
                    if (typeid(C).name() == component.first)
                        component.second->RemoveFromEntity(entity);
                }
            }

            template<class C>
            bool HasComponent(const EntityId entity) const
            {
                return true;
            }

        private:
            std::unordered_map<std::string, std::unique_ptr<IComponent>> p_registeredComponents;
    };
}
