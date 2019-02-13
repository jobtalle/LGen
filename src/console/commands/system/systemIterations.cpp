#include "console/commands/system/systemIterations.h"

using namespace LGen;

const std::string Command::System::Iterations::KEYWORD = "iterations";
const std::string Command::System::Iterations::FILE_HELP = "text/helpSystemIterations.txt";

Command::System::Iterations::Iterations() :
	Command({ KEYWORD }, FILE_HELP) {

}

void Command::System::Iterations::application(
	const std::vector<std::string> arguments,
	Console &console,
	Workspace &workspace) {
	if(!workspace.system) {
		console << Command::System::MSG_NO_SYSTEM << std::endl;

		return;
	}

	if(arguments.size() == 0) {
		console << Command::MSG_NEED_MORE_ARGUMENTS << std::endl;

		return;
	}

	try {
		workspace.system->setIterations(std::stoi(arguments[0]));
	}
	catch(...) {
		console << Command::MSG_INVALID_INPUT << std::endl;
	}
}