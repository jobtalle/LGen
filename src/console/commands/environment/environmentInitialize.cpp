#include "environmentInitialize.h"

using namespace LGen;

const std::string Command::Environment::Initialize::KEYWORD = "initialize";
const std::string Command::Environment::Initialize::ALIAS = "init";
const std::string Command::Environment::Initialize::FILE_HELP = "text/helpEnvironmentInitialize.txt";
const std::string Command::Environment::Initialize::MSG_NO_SYSTEM = "No system is currently loaded. A system is needed for initialization.";

Command::Environment::Initialize::Initialize() :
	Command({ KEYWORD, ALIAS }, FILE_HELP, 1) {
	
}

void Command::Environment::Initialize::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.environment) {
		console << MSG_NO_ENVIRONMENT << std::endl;

		return;
	}

	if(!workspace.system) {
		console << MSG_NO_SYSTEM << std::endl;

		return;
	}

	const float spacing = std::stof(arguments[ARG_SPACING]);

	workspace.environment->distributeAgents(*workspace.system, spacing);
}