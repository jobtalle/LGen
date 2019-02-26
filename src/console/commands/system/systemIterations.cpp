#include "console/commands/system/systemIterations.h"

using namespace LGen;

const std::string Command::System::Iterations::KEYWORD = "iterations";
const std::string Command::System::Iterations::ALIAS = "i";
const std::string Command::System::Iterations::FILE_HELP = "text/helpSystemIterations.txt";

Command::System::Iterations::Iterations() :
	Command({ KEYWORD, ALIAS }, FILE_HELP, 1) {

}

void Command::System::Iterations::application(
	const std::vector<std::string> arguments,
	Console &console,
	Workspace &workspace) {
	if(!workspace.system) {
		console << Command::System::MSG_NO_SYSTEM << std::endl;

		return;
	}

	try {
		workspace.systemIterations = std::stoi(arguments[ARG_ITERATIONS]);
	}
	catch(...) {
		console << Command::MSG_INVALID_INPUT << std::endl;
	}
}