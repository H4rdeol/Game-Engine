/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ECS.hpp
*/

#pragma once

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <map>

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
            void RemoveEntity(const EntityId entity);

            template<class C>

            void PrintEntities() const; // * Use for debug
        private:
            ECS() = default;
            ~ECS() = default;
        private:
            std::vector<EntityId> p_entities;
    };

    //TODO: @LO class Mapper with the unique_ptr or no of Components

    class ComponentsMapper {
        public:
            ComponentsMapper() = default;
            ~ComponentsMapper() = default;

            template<class C>
            void AddComponent(const EntityId entity, const C &component) const;

            template<class C>
            void RemoveComponent(const EntityId entity) const;

            template<class C>
            C &GetComponent(const EntityId entity) const;

            template<class C>
            bool HasComponent(const EntityId entity) const;
        private:
            std::map<EntityId, std::vector<std::size_t>> p_componentsIndexes;
    };

    struct PositionsComponents {
        std::vector<std::pair<float, float>> m_positions;
    };
}
