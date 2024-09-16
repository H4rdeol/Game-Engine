/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ECS.hpp
*/

#include <vector>
#include <memory>
#include <cassert>
// ? A templated class or abstract class to easily create mapper

namespace ECS
{
    class Camera; // TODO: @LO create Camera class

    class Scene {
        public:
            Scene() = default;
            ~Scene() = default;
            void AddEntity();
            void RemoveEntity();
        private:
            std::vector<std::size_t> entities;
    };
}
