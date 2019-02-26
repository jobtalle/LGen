#include "console/commands/system/systemRender.h"

#include <sstream>
#include <lrender.h>

using namespace LGen;

const std::string Command::System::Render::KEYWORD = "render";
const std::string Command::System::Render::FILE_HELP = "text/helpSystemRender.txt";

Command::System::Render::Render() :
	Command({ KEYWORD }, FILE_HELP, 0) {

}

void Command::System::Render::application(
	const std::vector<std::string> arguments,
	Console &console,
	Workspace &workspace) {
	if(!workspace.system) {
		console << Command::System::MSG_NO_SYSTEM << std::endl;

		return;
	}
	
	std::shared_ptr<LRender::Scene> scene(new LRender::Scene());

	scene->addAgent(LRender::Agent(
		LRender::Vector(0, 0, 0),
		workspace.system->generate(workspace.systemIterations, workspace.randomizer)->getString()));

	console.getMonitor()->setScene(scene);
}