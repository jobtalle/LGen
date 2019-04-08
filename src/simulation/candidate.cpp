#include "candidate.h"

using namespace LGen;

const float Candidate::RADIUS_OFFSET = 0.1f;

Candidate::Candidate(
	const float x,
	const float y,
	const LParse::System &system,
	const LRender::ReportLimits &limits,
	const float score) :
	x(x),
	y(y),
	system(system),
	radius(limits.getRadius() + RADIUS_OFFSET),
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

float Candidate::getScore() const {
	return score;
}

bool Candidate::compare(const Candidate& a, const Candidate& b) {
	return a.getScore() > b.getScore();
}
