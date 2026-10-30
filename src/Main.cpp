#include <print>
#include "PositionComponent.hpp"

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
    std::println("Hello World!");

	Gameol::ECS::PositionComponent positionComponent;

	positionComponent.addToEntity(1, { 10.0f, 20.0f });
	positionComponent.addToEntity(2, { 30.0f, 40.0f });

	positionComponent.removeFromEntity(1);
	return 0;
}
