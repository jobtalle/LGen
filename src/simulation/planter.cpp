#include "planter.h"
#include "simulation/utility.h"
#include "simulation/densityMap.h"

#include <algorithm>
#include <cmath>

using namespace LGen;

const float Planter::SPREAD = 0.5f;

Planter::Planter(
	const std::vector<Agent> &agents,
	const std::vector<LRender::ReportAgent> &reports,
	LParse::Randomizer &randomizer) {
	for(size_t i = 0; i < agents.size(); ++i) {
		const auto &report = reports[i];

		if(report.getSeeds().empty())
			continue;

		const auto &agent = agents[i];

		for(const auto &reportSeed : report.getSeeds()) {
			const auto direction = randomizer.makeFloat(0, LRender::Constants::PI * 2);
			const auto distance = std::sqrt(randomizer.makeFloat(0, 1)) * reportSeed.getLocation().y;

			candidates.emplace_back(
				reportSeed.getLocation().x + std::cos(direction) * distance,
				reportSeed.getLocation().z + std::sin(direction) * distance,
				agent.getSystem(),
				report.getLimits(),
				Utility::utility(report));
		}

		std::shuffle(candidates.end() - report.getSeeds().size(), candidates.end(), randomizer.getRandomizer());
	}

	std::sort(candidates.begin(), candidates.end(), Candidate::compare);
}

void Planter::plant(
	Environment &environment,
	const Mutator &mutator,
	LParse::Randomizer &randomizer) const {
	DensityMap densityMap(
		environment.getTerrain().getWidth(),
		environment.getTerrain().getHeight());

	for(const auto &candidate : candidates) {
		if(densityMap.sample(candidate.getX(), candidate.getY(), candidate.getRadius()) > 1)
			continue;

		if(
			candidate.getX() < 0 ||
			candidate.getY() < 0 ||
			candidate.getX() > environment.getTerrain().getWidth() ||
			candidate.getY() > environment.getTerrain().getHeight())
			continue;

		environment.addAgent(Agent(
			mutator.mutate(candidate.getSystem(), randomizer),
			candidate.getX(),
			candidate.getY()));

		densityMap.add(candidate);
	}
}
