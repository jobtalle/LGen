#pragma once

#include "environment/terrain/terrain.h"
#include "environment/agent/agent.h"

#include <memory>
#include <vector>

namespace LGen {
	class Environment final {
	public:
		Environment(const std::shared_ptr<Terrain> terrain);
		void addAgent(const Agent &agent);
		void clearAgents();

	private:
		const std::shared_ptr<Terrain> terrain;
		std::vector<Agent> agents;
	};
};