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
		std::make_unique<New>(),
		std::make_unique<Delete>(),
		std::make_unique<Render>(),
		std::make_unique<Terrain>(),
		std::make_unique<Save>(),
		std::make_unique<Load>(),
		std::make_unique<Initialize>()
	}) {

}