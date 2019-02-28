#include "environment.h"

using namespace LGen;

Environment::Environment(const std::shared_ptr<Terrain> terrain, const size_t maxIterations) :
	terrain(std::move(terrain)),
	maxIterations(maxIterations) {

}

void Environment::addAgent(const Agent &agent) {
	agents.push_back(agent);
}

void Environment::clearAgents() {
	agents.clear();
}

std::shared_ptr<LRender::Scene> Environment::makeScene(std::mt19937 &randomizer) const {
	std::shared_ptr<LRender::Scene> scene(new LRender::Scene());

	for(const auto &agent : agents)
		scene->addAgent(LRender::Agent(
			LRender::Vector(),
			agent.generate(maxIterations, randomizer)->getString()));

	return scene;
}