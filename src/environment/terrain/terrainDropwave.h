#pragma once

#include "environment/terrain/terrain.h"

namespace LGen {
	class TerrainDropwave final : public Terrain {
	public:
		TerrainDropwave(
			float width,
			float height,
			float period);
		float sample(float x, float y) const override;
		float getPeriod() const;

		static const std::string TYPE;
		
	private:
		const float period;
	};
}
