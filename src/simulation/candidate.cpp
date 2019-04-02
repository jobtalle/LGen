#include "candidate.h"

using namespace LGen;

Candidate::Candidate(
	const float x,
	const float y,
	const LParse::System &system,
	LRender::ReportLimits limits,
	const float score) :
	x(x),
	y(y),
	system(system),
	limits(std::move(limits)),
	score(score) {
	
}

float Candidate::getX() const {
	return x;
}

float Candidate::getY() const {
	return y;
}

const LParse::System& Candidate::getSystem() const {
	return system;
}

const LRender::ReportLimits &Candidate::getLimits() const {
	return limits;
}