#pragma once

#include "lrender.h"
#include "lparse.h"
#include "environment/agent/agent.h"
#include "environment/environment.h"
#include "simulation/candidate.h"
#include "simulation/mutator.h"

#include <vector>

namespace LGen {
	class Planter final {
	public:
		Planter(
			const std::vector<Agent> &agents,
			const std::vector<LRender::ReportAgent> &reports,
			LParse::Randomizer &randomizer);
		void plant(
			Environment &environment,
			const Mutator &mutator,
			float density,
			LParse::Randomizer &randomizer) const;

	private:
		static const float SPREAD;
		static const float DEFAULT_SPREAD;

		std::vector<Candidate> candidates;
	};
}