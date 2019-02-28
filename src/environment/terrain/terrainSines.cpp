#include "terrainSines.h"

#include <math.h>

using namespace LGen;

TerrainSines::TerrainSines(const float width, const float height) :
	Terrain(width, height) {

}

float TerrainSines::sample(const float x, const float y) const {
	return cos(sqrt(x * x + y * y) * 10);
}