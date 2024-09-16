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
            Scene();
            ~Scene();
            void AddEntity(std::size_t entity);
            void RemoveEntity(std::size_t entity);
            void SetCamera(std::unique_ptr<Camera> camera);
            Camera *GetCamera() const;
            std::vector<std::size_t> GetEntities() const;
        private:
            std::vector<std::size_t> entities;
            std::unique_ptr<Camera> camera;
    };
}
