#pragma once

#include "lrender.h"

namespace LGen {
	class Utility final {
	public:
		static float utility(const LRender::ReportAgent &report);
	};
}