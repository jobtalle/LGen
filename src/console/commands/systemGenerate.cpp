#include "console/commands/systemGenerate.h"
#include "workspace/workspaceSystem.h"

using namespace LGen;

const std::string Command::System::Generate::KEYWORD = "generate";
const std::string Command::System::Generate::FILE = "text/helpSystemGenerate.txt";

Command::System::Generate::Generate() :
	Command({ KEYWORD }, FILE) {

}

void Command::System::Generate::application(
	const std::vector<std::string> arguments,
	Console &console,
	Workspace &workspace) {
	console << workspace.getSystem().generate() << std::endl;
}