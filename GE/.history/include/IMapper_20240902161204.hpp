/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** IMapper.hpp
*/

#pragma once

#include <cstddef>

namespace ECS
{
    using EntityId = std::size_t;

    class IMapper {
        public:
            virtual ~IMapper() = default;
            virtual void AddEntity() = 0;
            virtual std::size_t GetIndex(const EntityId id) const = 0;
            virtual void RemoveEntity(const EntityId id) = 0;
    };
}
