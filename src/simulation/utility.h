#pragma once

#include "lrender.h"

namespace LGen {
	class Utility final {
	public:
		static double utility(const LRender::ReportAgent &report);
	};
}