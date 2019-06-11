#pragma once

#include "environment/terrain/terrain.h"

#include <cstddef>

namespace LGen {
	class TerrainValleys final : public Terrain {
	public:
		TerrainValleys(
			float width,
			float height,
			float resolution);
		float sample(float x, float y) const override;
		float getResolution() const;

		static const std::string TYPE;

	private:
		static const float DEAD_ZONE;

		const float resolution;
		const size_t xDivisions;
		const size_t yDivisions;
	};
}