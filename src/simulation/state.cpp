#include "state.h"

using namespace LGen;

State::State(
	std::unique_ptr<const Environment> environment,
	const LParse::Randomizer randomizer) :
	environment(std::move(environment)),
	randomizer(randomizer) {

}

void State::setRandomizer(LParse::Randomizer randomizer) {
	this->randomizer = randomizer;
}

const Environment &State::getEnvironment() const {
	return *environment;
}

const LParse::Randomizer &State::getRandomizer() const {
	return randomizer;
}

std::shared_ptr<LRender::Renderer::Task::SceneReport> State::getTaskSceneReport(
	const size_t threads,
	LParse::Randomizer *externalRandomizer) const {
	if(externalRandomizer)
		return std::make_shared<LRender::Renderer::Task::SceneReport>(
			environment->makeScene(threads, *externalRandomizer),
			externalRandomizer->makeRandomizer(),
			threads);

	auto renderRandomizer = randomizer;

	return std::make_shared<LRender::Renderer::Task::SceneReport>(
		environment->makeScene(threads, renderRandomizer),
		renderRandomizer.makeRandomizer(),
		threads);
}
