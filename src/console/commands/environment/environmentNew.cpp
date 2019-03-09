#include "environmentNew.h"

using namespace LGen;

const std::string Command::Environment::New::KEYWORD = "new";
const std::string Command::Environment::New::FILE_HELP = "text/helpEnvironmentNew.txt";

Command::Environment::New::New() :
	Command({ KEYWORD }, FILE_HELP, 0) {

}

void Command::Environment::New::application(
	const std::vector<std::string> arguments,
	Console &console) {
	workspace.environment = std::make_shared<LGen::Environment>();
}