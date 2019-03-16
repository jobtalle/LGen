#include "renderMode.h"
#include "console/commands/render/mode/renderModeDefault.h"
#include "console/commands/render/mode/renderModeWireframe.h"

using namespace LGen;

const std::string Command::Render::Mode::KEYWORD = "mode";
const std::string Command::Render::Mode::ALIAS = "m";

Command::Render::Mode::Mode() :
	Command({ KEYWORD, ALIAS }, {
		std::make_shared<Default>(),
		std::make_shared<Wireframe>()
	}) {

}