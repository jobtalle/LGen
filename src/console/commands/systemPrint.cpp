#include "console/commands/systemPrint.h"
#include "workspace/workspaceSystem.h"
#include <iostream>
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
	workspace.getSystem().print(console);
}