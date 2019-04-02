#include "candidate.h"

using namespace LGen;

Candidate::Candidate(
	const float x,
	const float y,
	const LParse::System &system,
	const LRender::ReportLimits &limits,
	const float score) :
	x(x),
	y(y),
	system(system),
	radius(limits.getRadius()),
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

float Candidate::getRadius() const {
	return radius;
}
