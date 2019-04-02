#pragma once

#include "report/reportLimits.h"

#include <vector>
#include <cstddef>

namespace LGen {
	class DensityMap final {
	public:
		DensityMap(float width, float height);
		void add(const LRender::ReportLimits &limits, float density);
		float sample(float x, float y) const;

	private:
		static const float GRID_SIZE;

		const size_t xCells;
		const size_t yCells;
		std::vector<float> grid;
	};
};