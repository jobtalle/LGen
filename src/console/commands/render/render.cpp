#include "render.h"
#include "console/commands/render/renderDefault.h"
#include "console/commands/render/renderWireframe.h"

using namespace LGen;

const std::string Command::Render::KEYWORD = "render";

Command::Render::Render() :
	Command({ KEYWORD }, {
		std::make_shared<Command::Render::Default>(),
		std::make_shared<Command::Render::Wireframe>()
	}) {

}