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
    class Camera; // TOF

    struct SceneComponent {
        std::vector<std::size_t> entities;

    };
}
