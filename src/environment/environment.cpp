#include "environment.h"
#include "simulation/profiles/growthProfileUnbounded.h"

using namespace LGen;

std::unique_ptr<Environment> Environment::makeEmptyCopy() const {
	auto environment = std::make_unique<Environment>();

	environment->setTerrain(terrain);

	return environment;
}

void Environment::setTerrain(std::shared_ptr<const Terrain> terrain) {
	clearAgents();

	this->terrain = std::move(terrain);
}

void Environment::setMaxIterations(const size_t maxIterations) {
	this->maxIterations = maxIterations;
}

void Environment::addAgent(const Agent &agent) {
	agents.push_back(agent);
}

void Environment::distributeAgents(const LParse::System &system, const float spacing) {
	const size_t xCount = std::ceil(this->terrain->getWidth() / spacing);
	const size_t yCount = std::ceil(this->terrain->getHeight() / spacing);
	const float xSpacing = this->terrain->getWidth() / xCount;
	const float ySpacing = this->terrain->getHeight() / yCount;

	agents.clear();

	for(size_t y = 1; y < yCount; ++y) for(size_t x = 1; x < xCount; ++x) {
		const auto agent = Agent(system, x * xSpacing, y * ySpacing);

		addAgent(agent);
	}
}

const std::vector<Agent>& Environment::getAgents() const {
	return agents;
}

size_t Environment::getMaxIterations() const {
	return maxIterations;
}

const Terrain &Environment::getTerrain() const {
	return *terrain;
}

void Environment::clearAgents() {
	agents.clear();
}

std::shared_ptr<LRender::Scene> Environment::makeScene(LParse::Randomizer &randomizer) const {
	const std::shared_ptr<const Terrain> &terrainSource = terrain;

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
			agent.generate(GrowthProfileUnbounded(maxIterations), randomizer)->getString()));

	return scene;
}

bool Environment::isComplete() const {
	return static_cast<bool>(terrain);
}