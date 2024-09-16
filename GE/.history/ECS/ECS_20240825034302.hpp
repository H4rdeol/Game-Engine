/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ECS.hpp
*/

#include <vector>
#include <memory>

// ? A templated class or abstract class to easily create mapper

namespace ECS
{
    class Camera; // TODO: @LO create Camera class

    class Scene {
        public:
            
        private:
            std::vector<std::size_t> entities;
            std::unique_ptr<Camera> camera;
    };
}
