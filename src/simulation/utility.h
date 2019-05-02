#pragma once

#include "lrender.h"

namespace LGen {
	class Utility final {
	public:
		Utility() = default;
		double utility(const LRender::ReportAgent &report) const;

	private:
		static const size_t MAX_ZERO_SURFACE_SYMBOLS = 55;
	};
}