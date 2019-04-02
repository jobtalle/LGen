#include "densityMap.h"

#include <cmath>
#include <algorithm>

using namespace LGen;

const float DensityMap::GRID_SIZE = 0.1f;

DensityMap::DensityMap(const float width, const float height) :
	xCells(std::ceil(width / GRID_SIZE)),
	yCells(std::ceil(height / GRID_SIZE)) {
	grid.resize(xCells * yCells);

	std::fill(grid.begin(), grid.end(), 0.0f);
}

void DensityMap::add(const Candidate &candidate) {
	size_t left = std::floor(candidate.getLimits().getMinimum().x / GRID_SIZE);
	size_t top = std::floor(candidate.getLimits().getMinimum().y / GRID_SIZE);
	size_t right = std::floor(candidate.getLimits().getMaximum().x / GRID_SIZE);
	size_t bottom = std::floor(candidate.getLimits().getMaximum().y / GRID_SIZE);

	if(left < 0) left = 0;
	if(top < 0) top = 0;
	if(right >= xCells) right = xCells - 1;
	if(bottom >= yCells) bottom = yCells - 1;

	for(size_t y = top; y <= bottom; ++y)
		for(size_t x = left; x <= right; ++x)
			grid[x + y * xCells] += 1;
}

float DensityMap::sample(const float x, const float y) const {
	const size_t xCell = std::floor(x / GRID_SIZE);
	const size_t yCell = std::floor(y / GRID_SIZE);

	return grid[xCell + yCell * xCells];
}
