#pragma once

#include "lparse.h"

#include <cstddef>

namespace LGen {
	class GrowthProfileQuadratic final : public LParse::GrowthProfile {
	public:
		GrowthProfileQuadratic(
			size_t iterations,
			size_t initial,
			float multiplier);
		size_t getGrowth(size_t iteration) const override;

	private:
		const size_t initial;
		const float multiplier;
	};
}