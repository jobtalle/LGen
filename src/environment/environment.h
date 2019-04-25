#pragma once

#include "environment/terrain/terrain.h"
#include "environment/agent/agent.h"
#include "lrender.h"
#include "lparse.h"

#include <memory>
#include <vector>
#include <cstddef>

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
		std::shared_ptr<LRender::Scene> makeScene(size_t threadCount, LParse::Randomizer &randomizer) const;
		bool isComplete() const;

	private:
		static const size_t BATCH_SIZE = 100;

		struct AgentBatch {
			AgentBatch(
				std::vector<Agent>::const_iterator begin,
				std::vector<Agent>::const_iterator end,
				LParse::Randomizer randomizer);

			const std::vector<Agent>::const_iterator begin;
			const std::vector<Agent>::const_iterator end;
			LParse::Randomizer randomizer;
			std::vector<LRender::Agent> agents;
		};

		static void generateBatches(
			const std::shared_ptr<const Terrain> &terrain,
			std::vector<AgentBatch>::iterator begin,
			std::vector<AgentBatch>::iterator end);

		std::shared_ptr<const Terrain> terrain;
		std::vector<Agent> agents;
	};
}