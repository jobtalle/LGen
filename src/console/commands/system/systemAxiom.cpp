#include "console/commands/system/systemAxiom.h"

using namespace LGen;

const std::string Command::System::Axiom::KEYWORD = "axiom";
const std::string Command::System::Axiom::ALIAS = "a";
const std::string Command::System::Axiom::FILE_HELP = "text/helpSystemAxiom.txt";

Command::System::Axiom::Axiom() :
	Command({ KEYWORD, ALIAS }, FILE_HELP, 1) {

}

void Command::System::Axiom::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.system) {
		console << MSG_NO_SYSTEM << std::endl;

		return;
	}

	workspace.system->setAxiom(arguments[ARG_SENTENCE]);
}