#include "utility.h"

using namespace LGen;

float Utility::utility(const LRender::ReportAgent& report) {
	if(report.getExposure().getExposure() == 0)
		return 0;

	return report.getExposure().getExposure() / report.getSize().getNodes();
}
