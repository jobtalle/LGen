#include "terrainValleys.h"
#include "math/constants.h"

#include <cmath>

using namespace LGen;

const std::string TerrainValleys::TYPE = "valleys";
const float TerrainValleys::DEAD_ZONE = 0.4f;

TerrainValleys::TerrainValleys(
	const float width,
	const float height,
	const float resolution) :
	Terrain(TYPE, width, height),
	resolution(resolution),
	xDivisions(std::ceil(width / resolution)),
	yDivisions(std::ceil(height / resolution)) {
	
}

float TerrainValleys::sample(const float x, const float y) const {
	const auto xRes = getWidth() / xDivisions;
	const auto yRes = getHeight() / yDivisions;
	const size_t xCell = std::floor(x / xRes);
	const size_t yCell = std::floor(y / yRes);
	const auto xValley = (xCell + 0.5f) * xRes;
	const auto yValley = (yCell + 0.5f) * yRes;
	const auto dx = 2 * (x - xValley) / xRes;
	const auto dy = 2 * (y - yValley) / yRes;

	return std::cos(LRender::Constants::PI * std::min(
		1.0f,
		std::max(0.0f, (1 + DEAD_ZONE) * std::sqrtf(dx * dx + dy * dy) - DEAD_ZONE))) * -0.5f + 0.5f;
}

float TerrainValleys::getResolution() const {
	return resolution;
}
