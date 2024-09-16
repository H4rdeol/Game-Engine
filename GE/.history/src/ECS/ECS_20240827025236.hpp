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

// ? A templated class or abstract class to easily create mapper

namespace ECS
{
    using EntityId = std::size_t;

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
            void RemoveEntity(EntityId entity);
            void PrintEntities() const;
        private:
            ECS() = default;
            ~ECS() = default;
        private:
            std::vector<EntityId> p_entities;
    };
}
