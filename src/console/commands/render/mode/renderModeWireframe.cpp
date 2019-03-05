#include "renderModeWireframe.h"

using namespace LGen;

const std::string Command::Render::Mode::Wireframe::KEYWORD = "wireframe";
const std::string Command::Render::Mode::Wireframe::FILE_HELP = "text/helpRenderWireframe.txt";

Command::Render::Mode::Wireframe::Wireframe() :
	Command({ KEYWORD }, FILE_HELP, 0) {

}

void Command::Render::Mode::Wireframe::application(
	const std::vector<std::string> arguments,
	Console &console,
	Workspace &workspace) {
	console.getMonitor()->enqueue(
		std::make_shared<LRender::Renderer::Task::Mode>(LRender::Renderer::Mode::WIREFRAME));
}