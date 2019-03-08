#pragma once

#include "terrain.h"

namespace LGen {
	class TerrainDropwave final : public Terrain {
	public:
		TerrainDropwave(
			const float width,
			const float height,
			const float period);
		float sample(const float x, const float y) const override;
		float getPeriod() const;

		static const std::string TYPE;
		
	private:
		const float period;
	};
}
