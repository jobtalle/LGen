#include "renderModeDefault.h"

using namespace LGen;

const std::string Command::Render::Mode::Default::KEYWORD = "default";
const std::string Command::Render::Mode::Default::ALIAS = "def";
const std::string Command::Render::Mode::Default::FILE_HELP = "text/helpRenderDefault.txt";

Command::Render::Mode::Default::Default() :
	Command({ KEYWORD, ALIAS }, FILE_HELP, 0) {

}

void Command::Render::Mode::Default::application(
	const std::vector<std::string> arguments,
	Console &console) {
	console.getMonitor()->enqueue(
		std::make_shared<LRender::Renderer::Task::Mode>(LRender::Renderer::Mode::DEFAULT));
}