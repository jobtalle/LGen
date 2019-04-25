#include "environment.h"

#include <thread>

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

void Environment::addAgent(const Agent &agent) {
	agents.push_back(agent);
}

void Environment::distributeAgents(const LParse::System &system, const float spacing) {
	const size_t xCount = std::ceil(this->terrain->getWidth() / spacing);
	const size_t yCount = std::ceil(this->terrain->getHeight() / spacing);
	const auto xSpacing = this->terrain->getWidth() / xCount;
	const auto ySpacing = this->terrain->getHeight() / yCount;

	agents.clear();

	for(size_t y = 1; y < yCount; ++y) for(size_t x = 1; x < xCount; ++x) {
		const auto agent = Agent(system, x * xSpacing, y * ySpacing);

		addAgent(agent);
	}
}

const std::vector<Agent>& Environment::getAgents() const {
	return agents;
}

const Terrain &Environment::getTerrain() const {
	return *terrain;
}

void Environment::clearAgents() {
	agents.clear();
}

std::shared_ptr<LRender::Scene> Environment::makeScene(const size_t threadCount, LParse::Randomizer &randomizer) const {
	struct AgentBatchRange {
		AgentBatchRange(
			const std::vector<AgentBatch>::iterator begin,
			const std::vector<AgentBatch>::iterator end) :
			begin(begin),
			end(end) { }

		const std::vector<AgentBatch>::iterator begin;
		const std::vector<AgentBatch>::iterator end;
	};

	const auto &terrainSource = terrain;

	LRender::Terrain renderTerrain(
		terrain->getWidth(),
		terrain->getHeight(),
		terrainSource,
		[terrainSource](const float x, const float y) {
			return terrainSource->get(x, y);
		});

	auto scene(std::make_shared<LRender::Scene>(renderTerrain));

	std::vector<AgentBatch> batches;

	for(size_t agent = 0; agent < agents.size(); agent += BATCH_SIZE) {
		auto end = agents.begin() + agent + BATCH_SIZE;

		if(end > agents.end())
			end = agents.end();

		batches.emplace_back(
			agents.begin() + agent,
			end,
			randomizer.makeRandomizer());
	}

	const size_t batchesPerThread = std::ceil(static_cast<float>(batches.size()) / threadCount);
	std::vector<AgentBatchRange> ranges;
	std::vector<std::thread> threads;

	for(size_t batch = 0; batch < batches.size(); batch += batchesPerThread) {
		auto end = batches.begin() + batch + batchesPerThread;

		if(end > batches.end())
			end = batches.end();

		ranges.emplace_back(AgentBatchRange(batches.begin() + batch, end));
		threads.emplace_back(generateBatches, terrain, batches.begin() + batch, end);
	}

	for(size_t threadIndex = 0; threadIndex < threads.size(); ++threadIndex) {
		threads[threadIndex].join();

		for(auto batch = ranges[threadIndex].begin; batch < ranges[threadIndex].end; ++batch)
			for(auto &agent : batch->agents)
				scene->addAgent(agent);
	}

	return scene;
}

bool Environment::isComplete() const {
	return static_cast<bool>(terrain);
}

void Environment::generateBatches(
	const std::shared_ptr<const Terrain> &terrain,
	const std::vector<AgentBatch>::iterator begin,
	const std::vector<AgentBatch>::iterator end) {
	for(auto batch = begin; batch < end; ++batch)
		for(auto agent = batch->begin; agent < batch->end; ++agent)
			batch->agents.emplace_back(
				LRender::Vector(
					agent->getX(),
					terrain->get(agent->getX(), agent->getY()),
					agent->getY()),
				agent->generate(
					*terrain->getGrowthProfile(agent->getX(), agent->getY()),
					batch->randomizer)->getString(),
				agent->getSystem().getRules().size(),
				terrain->getGrowthProfile(agent->getX(), agent->getY()));
}

Environment::AgentBatch::AgentBatch(
	const std::vector<Agent>::const_iterator begin,
	const std::vector<Agent>::const_iterator end,
	const LParse::Randomizer randomizer) :
	begin(begin),
	end(end),
	randomizer(randomizer) {
	
}
