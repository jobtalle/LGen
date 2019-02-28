#include "terrainSines.h"

#include <math.h>

using namespace LGen;

TerrainSines::TerrainSines(const float width, const float height) :
	Terrain(width, height) {

}

float TerrainSines::sample(const float x, const float y) const {
	const float dx = x - getWidth() * 0.5f;
	const float dy = y - getHeight() * 0.5f;

	return cos(sqrt(dx * dx + dy * dy));
}