#include "render.h"
#include "console/commands/render/mode/renderMode.h"

using namespace LGen;

const std::string Command::Render::KEYWORD = "render";

Command::Render::Render() :
	Command({ KEYWORD }, {
		std::make_unique<Mode>()
	}) {

}