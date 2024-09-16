/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Main.cpp
*/

#include "Application/Application.hpp"
#include <unordered_map>
#include <iostream>

int main(UNUSED int argc, UNUSED char *argv[])
{
    App::Application myApp {
        {
            sf::Vector2u(1920, 1080),
            "Test je cho",
            60,
            32
        }
    };

    myApp.run();
    return 0;
}
