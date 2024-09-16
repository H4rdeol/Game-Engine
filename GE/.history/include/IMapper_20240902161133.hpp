/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** IMapper.hpp
*/

#pragma once

#include "IComponent.hpp"
#include <cstddef>

namespace ECS
{
    using EntityId = std::size_t;

    class IMapper {
        public:
            virtual ~IMapper() = default;
            virtual std::size_t GetIndex() const = 0;
    };
}
