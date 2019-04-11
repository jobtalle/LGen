#pragma once

#include "lparse.h"

namespace LGen {
	class GrowthProfileUnbounded final : public LParse::GrowthProfile {
	public:
		GrowthProfileUnbounded(size_t iterations);
		size_t getGrowth(size_t iteration) const override;
	};
}