/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Application.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>

#define UNUSED __attribute__((unused))

namespace App {

    class Application {
        public:
            struct AppSettings {
                sf::Vector2u windowSize = sf::Vector2u(800, 600);
                std::string windowTitle = "My window";
                unsigned int frameRateLimit = 60;
                unsigned int bytePerPixel = 32;
            };
            Application(AppSettings settings);
            ~Application();
            void run();
        private:
            sf::RenderWindow p_window;
    };
}
