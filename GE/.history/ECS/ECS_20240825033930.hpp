/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ECS.hpp
*/

#include <vector>

// ? A templated class or abstract class to easily create mapper

namespace ECS
{
    struct SceneComponent {
        std::vector<int> entities;
    };
}
