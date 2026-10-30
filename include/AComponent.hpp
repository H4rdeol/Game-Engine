#pragma once

#include <unordered_map>
#include <vector>
#include <cstdint>

namespace Gameol::ECS {

	typedef size_t EntityId;

	template<typename T>
	class AComponent
	{
		public:
			AComponent()
			{
				data.emplace_back();
				data.back().reserve(PAGE_SIZE);
			}
			virtual ~AComponent() = default;

			virtual void addToEntity(EntityId id, T value) = 0;
			virtual void removeFromEntity(EntityId id) = 0;

		public:
			std::unordered_map<EntityId, std::pair<size_t, std::uint16_t>> idToIndexes;
			std::vector<std::vector<T>> data;
			static constexpr size_t PAGE_SIZE = 1000;
	};
}
