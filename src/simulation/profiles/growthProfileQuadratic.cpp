#include "growthProfileQuadratic.h"

using namespace LGen;

GrowthProfileQuadratic::GrowthProfileQuadratic(
	const size_t iterations,
	const size_t initial,
	const float multiplier) :
	GrowthProfile(iterations),
	initial(initial),
	multiplier(multiplier) {
	
}

size_t GrowthProfileQuadratic::getGrowth(const size_t iteration) const {
	return initial + static_cast<size_t>(multiplier * iteration * iteration);
}
