#include "terrainDemo.h"
#include "report/reportGrowthProfile.h"
#include "simulation/profiles/growthProfileUnbounded.h"

using namespace LGen;

const std::string TerrainDemo::TYPE = "demo";

TerrainDemo::TerrainDemo(
	const float width,
	const float height,
	const size_t iterations) :
	Terrain(TYPE, width, height),
	profile(std::make_shared<GrowthProfileUnbounded>(iterations)) {
	
}

float TerrainDemo::sample(float x, float y) const {
	return 0;
}

const std::shared_ptr<const LParse::GrowthProfile> &TerrainDemo::getGrowthProfile(float x, float y) const {
	return profile;
}
