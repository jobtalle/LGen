#pragma once

#include "lparse.h"

#include <cstddef>

namespace LGen {
	class GrowthProfileQuadratic final : public LParse::GrowthProfile {
	public:
		GrowthProfileQuadratic(size_t iterations, size_t growthInitial, size_t growthMultiplier);

	private:
		const size_t initial;
		const size_t
	};
}