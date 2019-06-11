#include "terrainFlat.h"

using namespace LGen;

const std::string TerrainFlat::TYPE = "flat";

TerrainFlat::TerrainFlat(
	const float width,
	const float height) :
	Terrain(TYPE, width, height) {

}

float TerrainFlat::sample(const float x, const float y) const {
	return 0;
}