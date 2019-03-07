#include "environmentLoad.h"
#include "file/fileEnvironment.h"

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
		const File::Environment file(arguments[ARG_FILE]);

		workspace.environment = std::make_unique<LGen::Environment>(file.getEnvironment());
	}
	catch(...) {
		console << MSG_ERROR << std::endl;
	}
}