/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ECS.hpp
*/

#pragma once

#include <cassert>
#include <vector>
#include <string>
#include <memory>
#include <set>

#include "ComponentMapper/ComponentMapper.hpp"
#include "IComponent.hpp"

namespace ECS
{
    class ComponentsManager;

    struct Entity {
        std::size_t id;
        std
    };

    class ECS {
        public:
            class ECSError : public std::exception {
                public:
                    ECSError(const std::string &msg);
                    const char *what() const noexcept override;
                private:
                    std::string p_msg;
            };

            ECS(const ECS &) = delete;
            ECS &operator=(const ECS &) = delete;

            static void Init();
            static void Shutdown();
            static ECS &GetInstance();

            void AddEntity();
            void RemoveEntity(const EntityId entity);
            bool HasEntity(const EntityId entity) const;

            void PrintEntities() const; // * Use for debug
        private:
            ECS() = default;
            ~ECS() = default;
        private:
            std::vector<EntityId> p_entities;
            std::unique_ptr<ComponentsManager> p_componentsMapper;
    };
}
