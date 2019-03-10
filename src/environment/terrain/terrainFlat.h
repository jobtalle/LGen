#pragma once

#include "environment/terrain/terrain.h"

namespace LGen {
	class TerrainFlat final : public Terrain {
	public:
		TerrainFlat(
			const float width,
			const float height);
		float sample(const float x, const float y) const override;

		static const std::string TYPE;
	};
}