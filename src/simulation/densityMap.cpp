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
	const auto left = getLeft(candidate.getX(), candidate.getRadius());
	const auto top = getTop(candidate.getY(), candidate.getRadius());
	const auto right = getRight(candidate.getX(), candidate.getRadius());
	const auto bottom = getBottom(candidate.getY(), candidate.getRadius());
	const auto squaredRadius = candidate.getRadius() * candidate.getRadius();

	for(size_t yCell = top; yCell <= bottom; ++yCell) for(size_t xCell = left; xCell <= right; ++xCell) {
		const float dx = candidate.getX() - (xCell + 0.5f) * GRID_SIZE;
		const float dy = candidate.getY() - (yCell + 0.5f) * GRID_SIZE;

		if(dx * dx + dy * dy < squaredRadius)
			grid[xCell + yCell * xCells] += 1;
	}
}

float DensityMap::sample(const float x, const float y, const float radius) const {
	const auto left = getLeft(x, radius);
	const auto top = getTop(y, radius);
	const auto right = getRight(x, radius);
	const auto bottom = getBottom(y, radius);
	const auto squaredRadius = radius * radius;
	size_t sampleCount = 0;
	float density = 0;

	for(size_t yCell = top; yCell <= bottom; ++yCell) for(size_t xCell = left; xCell <= right; ++xCell) {
		const float dx = x - (xCell + 0.5f) * GRID_SIZE;
		const float dy = y - (yCell + 0.5f) * GRID_SIZE;

		if(dx * dx + dy * dy < squaredRadius)
			++sampleCount, density += grid[xCell + yCell * xCells];
	}

	return density / sampleCount;
}

size_t DensityMap::getLeft(const float x, const float radius) {
	return std::floor(std::max(0.0f, x - radius) / GRID_SIZE);
}

size_t DensityMap::getTop(const float y, const float radius) {
	return std::floor(std::max(0.0f, y - radius) / GRID_SIZE);
}

size_t DensityMap::getRight(const float x, const float radius) const {
	size_t right = std::floor((x + radius) / GRID_SIZE);

	if(right >= xCells)
		right = xCells - 1;

	return right;
}

size_t DensityMap::getBottom(const float y, const float radius) const {
	size_t bottom = std::floor((y + radius) / GRID_SIZE);

	if(bottom >= yCells)
		bottom = yCells - 1;

	return bottom;
}
