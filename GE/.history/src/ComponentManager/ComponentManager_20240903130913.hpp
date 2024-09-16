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
#include <vector>

#include "ECS/ECS.hpp"
#include "AComponent.hpp"

namespace ECS
{
    class ComponentsManager {
        public:
            ComponentsManager();
            ~ComponentsManager() = default;

            template<class C, typename ...Args>
            void AddComponent(Entity &entity, C &component, Args... args)
            {
                assert(ECS::GetInstance().HasEntity(entity));

                component.AddToEntity(entity, args...);
            }

            template<class C>
            void RemoveComponent(Entity &entity) const
            {
                assert(ECS::GetInstance().HasEntity(entity));

                for (auto &component : p_registeredComponents) {
                    if (typeid(C).name() == component.first)
                        component.second->RemoveFromEntity(entity);
                }
            }

            template<class C>
            bool HasComponent(const Entity &entity) const
            {
                return entity.componentsName.contains(typeid(C).name());
            }

            template<class C>
            void RegisterComponent()
            {
                assert();

                p_registeredComponents[typeid(C).name()] = std::make_unique<C>();
                p_registeredComponentsName.insert(typeid(C).name());
            }

        private:
            std::set<std::string> p_registeredComponentsName;
            std::unordered_map<std::string, std::unique_ptr<AComponent>> p_registeredComponents;
    };
}
