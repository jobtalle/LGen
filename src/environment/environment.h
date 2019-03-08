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
		Environment();
		void setTerrain(const std::shared_ptr<Terrain> &terrain);
		void setMaxIterations(const size_t maxIterations);
		void addAgent(const Agent &agent);
		size_t getMaxIterations() const;
		std::shared_ptr<Terrain> getTerrain() const;
		void clearAgents();
		std::shared_ptr<LRender::Scene> makeScene(std::mt19937 &randomizer) const;
		bool isComplete() const;

	private:
		static const size_t DEFAULT_MAX_ITERATIONS = 4;

		std::shared_ptr<Terrain> terrain;
		std::vector<Agent> agents;
		size_t maxIterations;
	};
}