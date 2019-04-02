#include "densityMap.h"

#include <cmath>
#include <algorithm>

using namespace LGen;

const float DensityMap::GRID_SIZE = 0.1f;

DensityMap::DensityMap(const float width, const float height) :
	xCells(std::ceil(width / GRID_SIZE)),
	yCells(std::ceil(height / GRID_SIZE)) {
	grid.reserve(xCells * yCells);

	std::fill(grid.begin(), grid.end(), 0);
}

void DensityMap::add(const LRender::ReportLimits &limits, const float density) {
	const size_t left = std::floor(limits.getMinimum().x / GRID_SIZE);
	const size_t top = std::floor(limits.getMinimum().y / GRID_SIZE);
	const size_t right = std::floor(limits.getMaximum().x / GRID_SIZE);
	const size_t bottom = std::floor(limits.getMaximum().y / GRID_SIZE);

	for(size_t y = top; y <= bottom; ++y)
		for(size_t x = left; x <= right; ++x)
			grid[x + y * xCells] += density;
}

float DensityMap::sample(const float x, const float y) const {
	const size_t xCell = std::floor(x / GRID_SIZE);
	const size_t yCell = std::floor(y / GRID_SIZE);

	return grid[xCell + yCell * xCells];
}
