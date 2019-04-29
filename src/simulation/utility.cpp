#include "utility.h"

using namespace LGen;

double Utility::utility(const LRender::ReportAgent& report) {
	if(report.getExposure().getExposure() == 0) {
		if(report.getSize().getNodes() > MAX_ZERO_SURFACE_SYMBOLS)
			return -1;

		return 0;
	}

	// Exposure
	const auto factorExposure = report.getExposure().getExposure() / report.getSize().getNodes();

	// Seeds
	const auto factorSeeds = 1.0f / (report.getSeeds().size() * 0.05f + 1);

	// Rules
	const auto factorRules = 1.0f - report.getRules().getRuleCount() * 0.01f;

	// Stability
	auto averageDelta = (report.getPosition() - report.getAverage());
	averageDelta.y *= 0.05f;

	const auto factorStability = 1.0f / (averageDelta.length() * 0.05f + 1);

	// Leaf area
	float factorLeafArea = 0;

	for(const auto &leaf : report.getLeaves()) {
		const auto areaFactor = leaf.getArea() * 8;

		factorLeafArea += 1 - areaFactor * areaFactor;
	}

	factorLeafArea /= report.getLeaves().size();

	const auto utility = factorLeafArea * factorExposure * factorSeeds * factorRules * factorStability;

	return utility;
}
