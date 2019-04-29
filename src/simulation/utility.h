#pragma once

#include "lrender.h"

namespace LGen {
	class Utility final {
	public:
		static double utility(const LRender::ReportAgent &report, bool noiseless = false);

	private:
		static const size_t MAX_ZERO_SURFACE_SYMBOLS = 55;
		static const float NOISE;
	};
}