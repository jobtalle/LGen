#include "terrain.h"
#include "simulation/profiles/growthProfileQuadratic.h"

#include <utility>
#include <cmath>

using namespace LGen;

Terrain::Terrain(std::string type, const float width, const float height) :
	type(std::move(type)),
	width(width),
	height(height) {
	for(size_t i = 0; i < GROWTH_PROFILE_RESOLUTION; ++i)
		growthProfiles[i] = std::make_shared<GrowthProfileQuadratic>(
			1 + static_cast<size_t>(std::ceil(4.0f * (1.0f - (static_cast<float>(i) / GROWTH_PROFILE_RESOLUTION)))),
			24,
			(GROWTH_PROFILE_RESOLUTION - i) * 10.0f);
}

const std::string& Terrain::getType() const {
	return type;
}

float Terrain::getWidth() const {
	return width;
}

float Terrain::getHeight() const {
	return height;
}

float Terrain::get(const float x, const float y) const {
	return sample(x, y);
}

const std::shared_ptr<const LParse::GrowthProfile> &Terrain::getGrowthProfile(
	const float x,
	const float y) const {
	return growthProfiles[std::min(
		static_cast<size_t>(std::floor(get(x, y) * GROWTH_PROFILE_RESOLUTION)),
		GROWTH_PROFILE_RESOLUTION - 1)];
}
