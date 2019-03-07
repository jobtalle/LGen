#include "environment.h"
#include "console/commands/environment/environmentNew.h"
#include "console/commands/environment/environmentDelete.h"
#include "console/commands/environment/environmentRender.h"
#include "console/commands/environment/terrain/environmentTerrain.h"

using namespace LGen;

const std::string Command::Environment::KEYWORD = "environment";
const std::string Command::Environment::ALIAS = "env";
const std::string Command::Environment::MSG_NO_ENVIRONMENT = "No environment is loaded.";
const std::string Command::Environment::MSG_ENVIRONMENT_INCOMPLETE = "The current environment is incomplete.";

struct Command::Environment::Workspace Command::Environment::workspace = Command::Environment::Workspace();

Command::Environment::Environment() :
	Command({ KEYWORD, ALIAS }, {
		std::make_shared<Command::Environment::New>(),
		std::make_shared<Command::Environment::Delete>(),
		std::make_shared<Command::Environment::Render>(),
		std::make_shared<Command::Environment::Terrain>()
	}) {

}

Command::Environment::Workspace::Workspace() {

}