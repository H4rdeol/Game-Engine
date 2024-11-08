/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Components.cpp
*/

#ifndef MYPROJECT_SYSTEMS_HPP
    #define MYPROJECT_SYSTEMS_HPP

    #include "ASystems.hpp"
    #include "Application/Application.hpp"

    #include <array>
    #include <memory>

namespace ECS {

    class SystemsManager {
        public:
            enum class SystemType {
                POSITION,
                SPRITE,
                COUNT
            };
            SystemsManager();
            ~SystemsManager() = default;

            std::unique_ptr<ASystems> &operator[](SystemType type);
            void Update(float deltaTime);

        private:
            std::array<std::unique_ptr<ASystems>, (std::size_t)SystemType::COUNT> _systems;
    };

    class DrawSystem final : public ASystems {
        public:
            DrawSystem() = default;
            ~DrawSystem() final = default;
            void Update(float deltaTime) final;
    };
} // ECS

#endif //MYPROJECT_SYSTEMS_HPP
