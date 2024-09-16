/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Main.cpp
*/

// #include "Application/Application.hpp"
// #include "ECS/ECS.hpp"

// int main(UNUSED int argc, UNUSED char *argv[])
// {
//     ECS::ECS::Init();
//     App::Application myApp {
//         {
//             sf::Vector2u(1920, 1080),
//             "Test je cho",
//             60,
//             32
//         }
//     };

//     ECS::ECS::GetInstance().AddEntity();
//     ECS::ECS::GetInstance().AddEntity();
//     ECS::ECS::GetInstance().AddEntity();


//     ECS::ECS::GetInstance().RemoveEntity(1);
//     ECS::ECS::GetInstance().PrintEntities();
//     myApp.run();
//     ECS::ECS::Shutdown();
//     return 0;
// }

#include <set>
#include <iostream>

void printSet(const std::multiset<int> &mySet)
{
    for (const auto &elem : mySet)
        std::cout << elem << std::endl;
}

int main()
{
    std::multiset<int> mySet;

    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);
    mySet.insert(4);

    mySet.insert(3);
    mySet.emplace(6);

    printSet(mySet);
    mySet.extract(3);

    mySet.lower_bound(3)
    std::cout << "___________________" << std::endl;
    printSet(mySet);
    std::cout << "Nb 3: " << mySet.count(3) << std::endl;
    return 0;
}
