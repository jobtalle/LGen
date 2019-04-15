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
		std::unique_ptr<Environment> makeEmptyCopy() const;
		void setTerrain(std::shared_ptr<const Terrain> terrain);
		void addAgent(const Agent &agent);
		void distributeAgents(const LParse::System &system, float spacing);
		const std::vector<Agent> &getAgents() const;
		const Terrain &getTerrain() const;
		void clearAgents();
		std::shared_ptr<LRender::Scene> makeScene(LParse::Randomizer &randomizer) const;
		bool isComplete() const;

	private:
		std::shared_ptr<const Terrain> terrain;
		std::vector<Agent> agents;
	};
}