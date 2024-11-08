/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Application.cpp
*/

#include "Application.hpp"
#include "ECS/ECS.hpp"

namespace App {
    [[maybe_unused]] Application::Application(const AppSettings& settings)
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
        sf::Event event{};

        while (p_window.isOpen()) {
            p_window.clear();
            while (p_window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    p_window.close();
            }
            ECS::ECS::GetInstance().getSystemsManager()->Update(0.0f);
            p_window.display();
        }
    }

    sf::RenderWindow &Application::getWindow()
    {
        return p_window;
    }
}
