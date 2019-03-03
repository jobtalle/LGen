#include "renderWireframe.h"

using namespace LGen;

const std::string Command::Render::Wireframe::KEYWORD = "wireframe";
const std::string Command::Render::Wireframe::FILE_HELP = "text/helpRenderWireframe.txt";

Command::Render::Wireframe::Wireframe() :
	Command({ KEYWORD }, FILE_HELP, 0) {

}

void Command::Render::Wireframe::application(
	const std::vector<std::string> arguments,
	Console &console,
	Workspace &workspace) {
	console.getMonitor()->getRenderer()->setMode(LRender::Renderer::RenderMode::RENDER_WIREFRAME);
}