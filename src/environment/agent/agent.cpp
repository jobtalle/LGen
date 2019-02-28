#include "agent.h"

using namespace LGen;

Agent::Agent(const LParse::System &system) :
	system(system) {

}

std::shared_ptr<LParse::Sentence> Agent::generate(const size_t steps, std::mt19937 &randomizer) const {
	return system.generate(steps, randomizer);
}