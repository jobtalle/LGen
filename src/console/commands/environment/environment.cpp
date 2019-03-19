#include "environment.h"
#include "console/commands/environment/environmentNew.h"
#include "console/commands/environment/environmentDelete.h"
#include "console/commands/environment/environmentRender.h"
#include "console/commands/environment/environmentSave.h"
#include "console/commands/environment/environmentLoad.h"
#include "console/commands/environment/environmentInitialize.h"
#include "console/commands/environment/terrain/environmentTerrain.h"

using namespace LGen;

const std::string Command::Environment::KEYWORD = "environment";
const std::string Command::Environment::ALIAS = "env";
const std::string Command::Environment::MSG_NO_ENVIRONMENT = "No environment is loaded.";
const std::string Command::Environment::MSG_ENVIRONMENT_INCOMPLETE = "The current environment is incomplete.";

Command::Environment::Environment() :
	Command({ KEYWORD, ALIAS }, {
		std::make_shared<New>(),
		std::make_shared<Delete>(),
		std::make_shared<Render>(),
		std::make_shared<Terrain>(),
		std::make_shared<Save>(),
		std::make_shared<Load>(),
		std::make_shared<Initialize>()
	}) {

}