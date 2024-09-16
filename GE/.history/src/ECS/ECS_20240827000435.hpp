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
    class Scene {
        public:
            enum class PreExistingEntity: std::size_t {
                Camera = 0,
                NbPreExistingEntities
            };

            explicit Scene();
            ~Scene() = default;
            void AddEntity();
            void RemoveEntity();
        private:
            std::vector<std::size_t> entities;
    };

    class ECSa {
        public:
            ECSa() = default;
            ~ECS() = default;
            ECS(const ECS &cpy) = delete;
            ECS &operator=(const ECS &src) = delete;
            ECS(ECS &&src) = delete;
            ECS &operator=(ECS &&src) = delete;
    };
}
