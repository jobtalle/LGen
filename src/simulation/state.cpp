#include "state.h"

using namespace LGen;

State::State(
	std::unique_ptr<const Environment> environment,
	const LParse::Randomizer randomizer) :
	environment(std::move(environment)),
	randomizer(randomizer) {

}

const Environment &State::getEnvironment() const {
	return *environment;
}

const LParse::Randomizer &State::getRandomizer() const {
	return randomizer;
}

std::shared_ptr<LRender::Renderer::Task::Scene> State::getTaskScene() const {
	auto renderRandomizer = randomizer;

	return std::make_shared<LRender::Renderer::Task::Scene>(
		environment->makeScene(renderRandomizer),
		renderRandomizer);
}
