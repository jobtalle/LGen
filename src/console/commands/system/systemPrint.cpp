#include "console/commands/system/systemPrint.h"

using namespace LGen;

const std::string Command::System::Print::KEYWORD = "print";
const std::string Command::System::Print::FILE_HELP = "text/helpSystemPrint.txt";
const std::string Command::System::Print::MSG_AXIOM = "Axiom: ";
const std::string Command::System::Print::MSG_RULES = "Rules: ";
const std::string Command::System::Print::MSG_ITERATIONS = "Iterations: ";
const std::string Command::System::Print::PREFIX_RULE = "- ";

Command::System::Print::Print() :
	Command({ KEYWORD }, FILE_HELP) {

}

void Command::System::Print::application(
	const std::vector<std::string> arguments,
	Console &console,
	Workspace &workspace) {
	if(workspace.system) {
		console << MSG_AXIOM << workspace.system->getAxiom() << std::endl;
		console << MSG_ITERATIONS << workspace.system->getIterations() << std::endl;
		console << MSG_RULES << std::endl;

		for(auto &rule : workspace.system->getRules())
			console << PREFIX_RULE << rule << std::endl;
	}
	else
		console << Command::System::MSG_NO_SYSTEM << std::endl;
}