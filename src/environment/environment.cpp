#include "environment.h"

using namespace LGen;

Environment::Environment(const std::shared_ptr<Terrain> terrain) :
	terrain(std::move(terrain)) {

}

void Environment::addAgent(const Agent &agent) {
	agents.push_back(agent);
}

void Environment::clearAgents() {
	agents.clear();
}