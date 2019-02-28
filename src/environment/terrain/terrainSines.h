#pragma once

#include "terrain.h"

namespace LGen {
	class TerrainSines : public Terrain {
	public:
		TerrainSines(const float width, const float height);
		float sample(const float x, const float y) const override;
	};
};