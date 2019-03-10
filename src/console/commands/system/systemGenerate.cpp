#include "console/commands/system/systemGenerate.h"

using namespace LGen;

const std::string Command::System::Generate::KEYWORD = "generate";
const std::string Command::System::Generate::ALIAS = "gen";
const std::string Command::System::Generate::FILE_HELP = "text/helpSystemGenerate.txt";

Command::System::Generate::Generate() :
	Command({ KEYWORD, ALIAS }, FILE_HELP, 0) {

}

void Command::System::Generate::application(
	const std::vector<std::string> arguments,
	Console &console) {
	if(!workspace.system) {
		console << MSG_NO_SYSTEM << std::endl;

		return;
	}

	console << *workspace.system->generate(
		workspace.systemIterations,
		workspace.randomizer) << std::endl;
}