#pragma once

#include "terrain.h"

namespace LGen {
	class TerrainDropwave : public Terrain {
	public:
		TerrainDropwave(
			const float width,
			const float height,
			const float period);
		float sample(const float x, const float y) const override;
		
	private:
		const float period;
	};
}
