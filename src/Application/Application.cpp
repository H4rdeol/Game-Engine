/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Application.cpp
*/

#include "Application.hpp"

namespace App {
    Application::Application(AppSettings settings)
    {
        p_window.create(
            sf::VideoMode(
                settings.windowSize.x,
                settings.windowSize.y,
                settings.bytePerPixel
            ),
            settings.windowTitle,
            sf::Style::Close
        );
        p_window.setFramerateLimit(settings.frameRateLimit);
    }

    Application::~Application()
    {
        if (p_window.isOpen())
            p_window.close();
    }

    void Application::run()
    {
        while (p_window.isOpen()) {
            sf::Event event;
            while (p_window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    p_window.close();
            }
            p_window.clear();
            p_window.display();
        }
    }
}
