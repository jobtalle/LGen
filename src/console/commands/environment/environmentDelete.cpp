#include "environmentDelete.h"

using namespace LGen;

const std::string Command::Environment::Delete::KEYWORD = "delete";
const std::string Command::Environment::Delete::FILE_HELP = "text/helpEnvironmentDelete.txt";

Command::Environment::Delete::Delete() :
	Command({ KEYWORD }, FILE_HELP, 0) {

}

void Command::Environment::Delete::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	workspace.environment = nullptr;
}