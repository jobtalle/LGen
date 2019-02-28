#pragma once

#include "environment/terrain/terrain.h"
#include "environment/agent/agent.h"
#include "lrender.h"

#include <memory>
#include <vector>
#include <random>

namespace LGen {
	class Environment final {
	public:
		Environment(const std::shared_ptr<Terrain> terrain, const size_t maxIterations);
		void addAgent(const Agent &agent);
		void clearAgents();
		std::shared_ptr<LRender::Scene> makeScene(std::mt19937 &randomizer) const;

	private:
		const std::shared_ptr<Terrain> terrain;
		std::vector<Agent> agents;
		size_t maxIterations;
	};
};