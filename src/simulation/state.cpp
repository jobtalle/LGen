#include "state.h"

using namespace LGen;

State::State(
	std::unique_ptr<const Environment> environment,
	const LParse::Randomizer randomizer,
	const size_t generation) :
	environment(std::move(environment)),
	randomizer(randomizer),
	generation(generation) {

}

const Environment &State::getEnvironment() const {
	return *environment;
}

const LParse::Randomizer &State::getRandomizer() const {
	return randomizer;
}

size_t State::getGeneration() const {
	return generation;
}

std::shared_ptr<LRender::Renderer::Task::Scene> State::getTaskScene() const {
	auto renderRandomizer = randomizer;

	return std::make_shared<LRender::Renderer::Task::Scene>(
		environment->makeScene(renderRandomizer),
		renderRandomizer);
}
