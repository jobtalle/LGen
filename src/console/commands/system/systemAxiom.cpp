#include "console/commands/system/systemAxiom.h"

using namespace LGen;

const std::string Command::System::Axiom::KEYWORD = "axiom";
const std::string Command::System::Axiom::FILE = "text/helpSystemAxiom.txt";

Command::System::Axiom::Axiom() :
	Command({ KEYWORD }, FILE) {

}

void Command::System::Axiom::application(
	const std::vector<std::string> arguments,
	Console &console,
	Workspace &workspace) {
	if(arguments.size() == 0) {
		console << Command::MSG_NEED_MORE_ARGUMENTS << std::endl;

		return;
	}

	workspace.system->setAxiom(arguments[0]);
}