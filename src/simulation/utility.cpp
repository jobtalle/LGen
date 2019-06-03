#include "utility.h"

using namespace LGen;

double Utility::utility(const LRender::ReportAgent &report) const {
	if(report.getExposure().getExposure() == 0) {
		if(report.getSize().getNodes() > MAX_ZERO_SURFACE_SYMBOLS)
			return -1;

		return 0;
	}

	if(report.getLimits().getMinimum().y < report.getPosition().y)
		return -1;

	return
		getFactorSeeds(report) *
		getFactorRules(report) *
		getFactorStability(report) *
		getFactorLeaves(report) *
		getFactorExposure(report);
}

double Utility::getFactorExposure(const LRender::ReportAgent &report) const {
	return std::pow(report.getExposure().getExposure(), 2.0f) / report.getSize().getNodes();
}

double Utility::getFactorSeeds(const LRender::ReportAgent &report) const {
	return 1.0f / (report.getSeeds().size() * 0.05f + 1);
}

double Utility::getFactorRules(const LRender::ReportAgent &report) const {
	return 1.0f / (report.getRules().getRuleCount() * 0.05f + 1);
}

double Utility::getFactorStability(const LRender::ReportAgent &report) const {
	auto averageDelta = (report.getPosition() - report.getAverage());

	const auto eccentricity = averageDelta.length();

	return 1.0f / (eccentricity * eccentricity * 0.3f + 1);
}

double Utility::getFactorLeaves(const LRender::ReportAgent &report) const {
	float factorLeafArea = 0;

	for(const auto &leaf : report.getLeaves()) {
		const auto areaFactor = leaf.getArea() * 8;

		factorLeafArea += 1 - areaFactor * areaFactor;
	}

	factorLeafArea /= report.getLeaves().size();

	return factorLeafArea;
}