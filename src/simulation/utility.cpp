#include "utility.h"

using namespace LGen;

double Utility::utility(const LRender::ReportAgent &report) const {
	if(report.getExposure().getExposure() == 0) {
		if(report.getSize().getNodes() > MAX_ZERO_SURFACE_SYMBOLS)
			return -1;

		return 0;
	}

	return
		getFactorSeeds(report) *
		getFactorRules(report) *
		getFactorStability(report) *
		getFactorLeaves(report) *
		getFactorEfficiency(report);
}

double Utility::getFactorSeeds(const LRender::ReportAgent &report) const {
	return 1.0f / (report.getSeeds().size() * 0.05f + 1);
}

double Utility::getFactorRules(const LRender::ReportAgent &report) const {
	return 1.0f - report.getRules().getRuleCount() * 0.01f;
}

double Utility::getFactorStability(const LRender::ReportAgent &report) const {
	auto averageDelta = (report.getPosition() - report.getAverage());

	averageDelta.y *= 0.05f;

	return 1.0f / (averageDelta.length() * 0.05f + 1);
}

double Utility::getFactorLeaves(const LRender::ReportAgent &report) const {
	float factorLeafArea = 0;
	float leafArea = 0;

	for(const auto &leaf : report.getLeaves()) {
		leafArea += leaf.getArea();

		const auto areaFactor = std::max(0.0f, leafArea) * 7;

		factorLeafArea += 1 - areaFactor * areaFactor;
	}

	factorLeafArea /= report.getLeaves().size();

	const auto factorExposure = report.getExposure().getExposure() / leafArea;

	return factorExposure * factorLeafArea;
}

double Utility::getFactorEfficiency(const LRender::ReportAgent &report) const {
	return report.getExposure().getExposure() / report.getSize().getNodes();
}
