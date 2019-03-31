#pragma once

#include "../environment/environment.h"
#include "lrender.h"

#include <memory>

namespace LGen {
	class State final {
	public:
		State(
			std::unique_ptr<const Environment> environment,
			LParse::Randomizer randomizer,
			size_t generation);
		const Environment &getEnvironment() const;
		const LParse::Randomizer &getRandomizer() const;
		size_t getGeneration() const;
		std::shared_ptr<LRender::Renderer::Task::Scene> getTaskScene() const;

	private:
		const std::unique_ptr<const Environment> environment;
		const LParse::Randomizer randomizer;
		const size_t generation;
	};
}