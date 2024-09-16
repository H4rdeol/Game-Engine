/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Entity.h
*/

#pragma once

#include "C"

#include <cstddef>
#include <set>

struct Entity {
    std::size_t id;
    std::set<> components;
};
