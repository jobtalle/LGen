#include "growthProfileUnbounded.h"

#include <limits>

using namespace LGen;

GrowthProfileUnbounded::GrowthProfileUnbounded(size_t iterations) :
	GrowthProfile(iterations) {
	
}

size_t GrowthProfileUnbounded::getGrowth(size_t iteration) const {
	return std::numeric_limits<size_t>::max();
}
