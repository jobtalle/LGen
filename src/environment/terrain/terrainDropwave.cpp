#include "terrainDropwave.h"

#include <math.h>

using namespace LGen;

TerrainDropwave::TerrainDropwave(const float width, const float height) :
	Terrain(width, height) {

}

float TerrainDropwave::sample(const float x, const float y) const {
	const float dx = x - getWidth() * 0.5f;
	const float dy = y - getHeight() * 0.5f;

	return cos(sqrt(dx * dx + dy * dy));
}