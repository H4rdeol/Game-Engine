#include "PositionComponent.hpp"

namespace Gameol::ECS {

	void PositionComponent::addToEntity(EntityId id, std::pair<float, float> position)
	{
		if (idToIndexes.find(id) != idToIndexes.end())
			return;

		if (data.back().size() >= PAGE_SIZE)
		{
			data.emplace_back();
			data.back().reserve(PAGE_SIZE);
		}

		size_t pageIndex = data.size() - 1;
		size_t indexInPage = data.back().size();
		data.back().emplace_back(position);
		idToIndexes[id] = { pageIndex, static_cast<std::uint16_t>(indexInPage) };
	}

	void PositionComponent::removeFromEntity(EntityId id)
	{
		auto it = idToIndexes.find(id);
		if (it == idToIndexes.end())
			return;

		auto [pageIndex, indexInPage] = it->second;
		data[pageIndex].erase(data[pageIndex].begin() + indexInPage);
		idToIndexes.erase(it);

		if (data.back().empty() && data.size() > 1)
			data.pop_back();
	}
}
