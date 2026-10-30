#pragma once

#include "AComponent.hpp"

namespace Gameol::ECS {

	class PositionComponent: public AComponent<std::pair<float, float>>
	{
		public:
			PositionComponent() = default;
			~PositionComponent() = default;

			void addToEntity(EntityId id, std::pair<float, float> position) override;
			void removeFromEntity(EntityId id) override;
	};
}
