#include "workspace/workspaceSystem.h"

using namespace LGen;

const std::string Workspace::System::MSG_SYSTEM_INVALID = "The current system is incomplete.";

void Workspace::System::create() {
	system.reset(new LParse::System(
	LParse::Sentence({ 'A' }),
	{ 
		LParse::Rule(LParse::Sentence({ 'A' }), LParse::Sentence({ 'B' })),
		LParse::Rule(LParse::Sentence({ 'B' }), LParse::Sentence({ 'A' })) },
	3));
}

void Workspace::System::destroy() {
	system.reset(nullptr);
}

std::string Workspace::System::generate() {
	if(system && system->isComplete())
		system->generate(randomizer);

	return "test";
}

void Workspace::System::print(std::ostream &stream) const {
	if(system && system->isComplete())
		stream << *system;
	else
		stream << MSG_SYSTEM_INVALID << std::endl;
}