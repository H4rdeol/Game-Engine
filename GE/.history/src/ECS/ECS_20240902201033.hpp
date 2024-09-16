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

#include "ECS/Entity.h"
#include "ComponentManager/ComponentManager.hpp"

namespace ECS
{
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
            void RemoveEntity(const std::size_t entityId);
            bool HasEntity(const Entity entity) const;

            void PrintEntities() const; // * Use for debug
        private:
            ECS() = default;
            ~ECS() = default;
        private:
            std::vector<Entity> p_entities;
            std::unique_ptr<ComponentsManager> p_componentsMapper;
    };
}
