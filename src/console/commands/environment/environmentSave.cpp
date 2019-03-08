#include "environmentSave.h"
#include "file/fileEnvironment.h"

using namespace LGen;

const std::string Command::Environment::Save::KEYWORD = "save";
const std::string Command::Environment::Save::FILE_HELP = "text/helpEnvironmentSave.txt";
const std::string Command::Environment::Save::MSG_ERROR = "Error while saving the environment.";

Command::Environment::Save::Save() :
	Command({ KEYWORD }, FILE_HELP, 1) {

}

void Command::Environment::Save::application(
	const std::vector<std::string> arguments,
	Console &console) {
	if(!workspace.environment) {
		console << MSG_NO_ENVIRONMENT << std::endl;

		return;
	}

	try {
		FileEnvironment::serialize(*workspace.environment).save(arguments[ARG_FILE]);
	}
	catch(...) {
		console << MSG_ERROR << std::endl;
	}
}