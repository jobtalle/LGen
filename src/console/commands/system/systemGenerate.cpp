#include "console/commands/system/systemGenerate.h"

using namespace LGen;

const std::string Command::System::Generate::KEYWORD = "generate";
const std::string Command::System::Generate::FILE_HELP = "text/helpSystemGenerate.txt";

Command::System::Generate::Generate() :
	Command({ KEYWORD }, FILE_HELP) {

}

void Command::System::Generate::application(
	const std::vector<std::string> arguments,
	Console &console,
	Workspace &workspace) {
	if(!workspace.system) {
		console << Command::System::MSG_NO_SYSTEM << std::endl;

		return;
	}

	if(workspace.system->isComplete())
		console << *workspace.system->generate(workspace.randomizer) << std::endl;
	else
		console << Command::System::MSG_SYSTEM_INCOMPLETE << std::endl;
}