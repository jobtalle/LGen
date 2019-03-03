#include "renderDefault.h"

using namespace LGen;

const std::string Command::Render::Default::KEYWORD = "default";
const std::string Command::Render::Default::ALIAS = "def";
const std::string Command::Render::Default::FILE_HELP = "text/helpRenderDefault.txt";

Command::Render::Default::Default() :
	Command({ KEYWORD, ALIAS }, FILE_HELP, 0) {

}

void Command::Render::Default::application(
	const std::vector<std::string> arguments,
	Console &console,
	Workspace &workspace) {
	console.getMonitor()->getRenderer()->setMode(LRender::Renderer::RenderMode::RENDER_DEFAULT);
}