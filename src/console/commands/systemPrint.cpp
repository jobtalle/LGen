#include "console/commands/systemPrint.h"

using namespace LGen;

const std::string Command::System::Print::KEYWORD = "print";
const std::string Command::System::Print::FILE = "text/helpSystemPrint.txt";

Command::System::Print::Print() :
	Command({ KEYWORD }, FILE) {

}

void Command::System::Print::application(
	const std::vector<std::string> arguments,
	Console &console,
	Workspace &workspace) {
	if(workspace.system)
		console << *workspace.system;
	else
		console << Command::System::MSG_NO_SYSTEM;
}