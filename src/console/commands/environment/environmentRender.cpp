#include "environmentRender.h"

using namespace LGen;

const std::string Command::Environment::Render::KEYWORD = "render";
const std::string Command::Environment::Render::FILE_HELP = "text/helpEnvironmentRender.txt";

Command::Environment::Render::Render() :
	Command({ KEYWORD }, FILE_HELP, 0) {

}

void Command::Environment::Render::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.environment) {
		console << MSG_NO_ENVIRONMENT << std::endl;

		return;
	}

	if(!workspace.environment->isComplete()) {
		console << MSG_ENVIRONMENT_INCOMPLETE << std::endl;

		return;
	}

	const auto task = std::make_shared<LRender::Renderer::Task::SceneReport>(
		workspace.environment->makeScene(workspace.randomizer),
		workspace.randomizer.makeRandomizer(),
		workspace.threadCount);

	console.getMonitor()->makeVisible();
	console.getMonitor()->enqueue(task);
}