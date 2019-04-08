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
	size_t left = std::floor(std::max(0.0f, candidate.getX() - candidate.getRadius()) / GRID_SIZE);
	size_t top = std::floor(std::max(0.0f, candidate.getY() - candidate.getRadius()) / GRID_SIZE);
	size_t right = std::floor((candidate.getX() + candidate.getRadius()) / GRID_SIZE);
	size_t bottom = std::floor((candidate.getY() + candidate.getRadius()) / GRID_SIZE);
	
	if(left < 0) left = 0;
	if(top < 0) top = 0;
	if(right >= xCells) right = xCells - 1;
	if(bottom >= yCells) bottom = yCells - 1;

	const float squaredRadius = candidate.getRadius() * candidate.getRadius();

	for(size_t y = top; y <= bottom; ++y) for(size_t x = left; x <= right; ++x) {
		const float dx = candidate.getX() - (x + 0.5f) * GRID_SIZE;
		const float dy = candidate.getY() - (y + 0.5f) * GRID_SIZE;

		if(dx * dx + dy * dy < squaredRadius)
			grid[x + y * xCells] += 1;
	}
}

float DensityMap::sample(const float x, const float y) const {
	const size_t xCell = std::floor(x / GRID_SIZE);
	const size_t yCell = std::floor(y / GRID_SIZE);

	return grid[xCell + yCell * xCells];
}