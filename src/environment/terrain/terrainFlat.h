#pragma once

#include "environment/terrain/terrain.h"

namespace LGen {
	class TerrainFlat final : public Terrain {
	public:
		TerrainFlat(
			float width,
			float height);
		float sample(float x, float y) const override;

		static const std::string TYPE;
	};
}