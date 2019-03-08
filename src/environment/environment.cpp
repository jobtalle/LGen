#include "environment.h"

using namespace LGen;

Environment::Environment() :
	maxIterations(DEFAULT_MAX_ITERATIONS) {

}

void Environment::setTerrain(const std::shared_ptr<Terrain> &terrain) {
	this->terrain = terrain;
}

void Environment::setMaxIterations(const size_t maxIterations) {
	this->maxIterations = maxIterations;
}

void Environment::addAgent(const Agent &agent) {
	agents.push_back(agent);
}

size_t Environment::getMaxIterations() const {
	return maxIterations;
}

std::shared_ptr<Terrain> Environment::getTerrain() const {
	return terrain;
}

void Environment::clearAgents() {
	agents.clear();
}

std::shared_ptr<LRender::Scene> Environment::makeScene(std::mt19937 &randomizer) const {
	const std::shared_ptr<Terrain> &terrainSource = terrain;

	LRender::Terrain renderTerrain(
		terrain->getWidth(),
		terrain->getHeight(),
		terrainSource,
		[terrainSource](const float x, const float y) {
			return terrainSource->get(x, y);
		});

	std::shared_ptr<LRender::Scene> scene(std::make_shared<LRender::Scene>(renderTerrain));

	for(const auto &agent : agents)
		scene->addAgent(LRender::Agent(
			LRender::Vector(
				agent.getX(),
				terrain->get(agent.getX(), agent.getY()),
				agent.getY()),
			agent.generate(maxIterations, randomizer)->getString()));

	return scene;
}

bool Environment::isComplete() const {
	if(!terrain)
		return false;

	return true;
}