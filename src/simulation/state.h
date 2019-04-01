#pragma once

#include "../environment/environment.h"
#include "lrender.h"

#include <memory>

namespace LGen {
	class State final {
	public:
		State(
			std::unique_ptr<const Environment> environment,
			LParse::Randomizer randomizer);
		const Environment &getEnvironment() const;
		const LParse::Randomizer &getRandomizer() const;
		std::shared_ptr<LRender::Renderer::Task::Scene> getTaskScene() const;
		std::shared_ptr<LRender::Renderer::Task::SceneReport> getTaskSceneReport(
			LParse::Randomizer *externalRandomizer = nullptr) const;

	private:
		const std::unique_ptr<const Environment> environment;
		const LParse::Randomizer randomizer;
	};
}