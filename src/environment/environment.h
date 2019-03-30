#pragma once

#include "environment/terrain/terrain.h"
#include "environment/agent/agent.h"
#include "lrender.h"
#include "lparse.h"

#include <memory>
#include <vector>

namespace LGen {
	class Environment final {
	public:
		Environment() = default;
		Environment(const Environment &other) = default;
		void setTerrain(std::shared_ptr<const Terrain> terrain);
		void setMaxIterations(size_t maxIterations);
		void addAgent(const Agent &agent);
		void distributeAgents(const LParse::System &system, const float spacing);
		const std::vector<Agent> &getAgents() const;
		size_t getMaxIterations() const;
		const Terrain &getTerrain() const;
		void clearAgents();
		std::shared_ptr<LRender::Scene> makeScene(LParse::Randomizer &randomizer) const;
		bool isComplete() const;

	private:
		static const size_t DEFAULT_MAX_ITERATIONS = 4;

		std::shared_ptr<const Terrain> terrain;
		std::vector<Agent> agents;
		size_t maxIterations = DEFAULT_MAX_ITERATIONS;
	};
}