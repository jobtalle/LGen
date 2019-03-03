#include "console/commands/system/systemRender.h"
#include "environment/environment.h"
#include "environment/terrain/terrainSines.h"

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
	
	Environment environment(
		std::make_shared<TerrainSines>(TerrainSines(20, 20)),
		workspace.systemIterations);

	environment.addAgent(Agent(*workspace.system));

	console.getMonitor()->setScene(environment.makeScene(workspace.randomizer));
}