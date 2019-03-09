#include "environmentLoad.h"
#include "file/fileEnvironment.h"
#include <stdlib.h>

using namespace LGen;

const std::string Command::Environment::Load::KEYWORD = "load";
const std::string Command::Environment::Load::FILE_HELP = "text/helpEnvironmentLoad.txt";
const std::string Command::Environment::Load::MSG_ERROR = "Error while loading the environment.";

Command::Environment::Load::Load() :
	Command({ KEYWORD }, FILE_HELP, 1) {

}

void Command::Environment::Load::application(
	const std::vector<std::string> arguments,
	Console &console) {
	try {
		workspace.environment << File(arguments[ARG_FILE]);
	}
	catch(...) {
		console << MSG_ERROR << std::endl;
	}
}