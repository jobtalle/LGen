#include "growthProfileQuadratic.h"

using namespace LGen;

GrowthProfileQuadratic::GrowthProfileQuadratic(
	const size_t iterations,
	const size_t initial,
	const size_t multiplier) :
	GrowthProfile(iterations),
	initial(initial),
	multiplier(multiplier) {
	
}

size_t GrowthProfileQuadratic::getGrowth(const size_t iteration) const {
	return initial + multiplier * iteration * iteration;
}
