#pragma once

#include "lrender.h"

namespace LGen {
	class Utility final {
	public:
		Utility() = default;
		double utility(const LRender::ReportAgent &report) const;

	private:
		static const size_t MAX_ZERO_SURFACE_SYMBOLS = 55;

		double getFactorExposure(const LRender::ReportAgent &report) const;
		double getFactorSeeds(const LRender::ReportAgent &report) const;
		double getFactorRules(const LRender::ReportAgent &report) const;
		double getFactorStability(const LRender::ReportAgent &report) const;
		double getFactorLeaves(const LRender::ReportAgent &report) const;
	};
}