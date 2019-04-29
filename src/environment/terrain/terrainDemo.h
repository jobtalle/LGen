#pragma once

#include "environment/terrain/terrain.h"

namespace LGen {
	class TerrainDemo final : public Terrain {
	public:
		TerrainDemo(
			float width,
			float height,
			size_t iterations);
		float sample(float x, float y) const override;
		const std::shared_ptr<const LParse::GrowthProfile> &getGrowthProfile(float x, float y) const override;

		static const std::string TYPE;

	private:
		std::shared_ptr<const LParse::GrowthProfile> profile;
	};
}