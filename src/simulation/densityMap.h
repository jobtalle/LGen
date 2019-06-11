#pragma once

#include "simulation/candidate.h"

#include <vector>
#include <cstddef>

namespace LGen {
	class DensityMap final {
	public:
		DensityMap(float width, float height);
		void add(const Candidate &candidate);
		float sample(float x, float y, float radius) const;

	private:
		static const float GRID_SIZE;

		const size_t xCells;
		const size_t yCells;
		std::vector<size_t> grid;

		static size_t getLeft(float x, float radius);
		static size_t getTop(float y, float radius);
		size_t getRight(float x, float radius) const;
		size_t getBottom(float y, float radius) const;
	};
}