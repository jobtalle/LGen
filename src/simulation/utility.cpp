#include "utility.h"

using namespace LGen;

double Utility::utility(const LRender::ReportAgent& report) {
	if(report.getExposure().getExposure() == 0)
		return 0;

	float factorLeafArea = 0;
	const auto factorExposure = report.getExposure().getExposure() / report.getSize().getNodes();
	const auto factorSeeds = 1.0f / (report.getSeeds().size() * 0.05f + 1);

	for(const auto &leaf : report.getLeaves())
		factorLeafArea += 1 - (leaf.getArea() * 0.1f) * (leaf.getArea() * 0.1f);

	factorLeafArea /= report.getLeaves().size();

	return factorLeafArea * factorExposure * factorSeeds;
}
