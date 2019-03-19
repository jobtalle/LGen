#include "agent.h"

using namespace LGen;

Agent::Agent(const LParse::System &system, const float x, const float y) :
	system(system),
	x(x),
	y(y) {

}

std::shared_ptr<LParse::Sentence> Agent::generate(const size_t steps, std::mt19937 &randomizer) const {
	return system.generate(steps, randomizer);
}

const LParse::System& Agent::getSystem() const {
	return system;
}

float Agent::getX() const {
	return x;
}

float Agent::getY() const {
	return y;
}