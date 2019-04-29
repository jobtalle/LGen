#include "console/commands/system/systemRender.h"
#include "environment/environment.h"
#include "lrender.h"

#include <sstream>
#include "environment/terrain/terrainDemo.h"

using namespace LGen;

const std::string Command::System::Render::KEYWORD = "render";
const std::string Command::System::Render::FILE_HELP = "text/helpSystemRender.txt";
const float Command::System::Render::TERRAIN_SIZE = 10;

Command::System::Render::Render() :
	Command({ KEYWORD }, FILE_HELP, 0) {

}

void Command::System::Render::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.system) {
		console << MSG_NO_SYSTEM << std::endl;

		return;
	}
	
	LGen::Environment environment;

	environment.setTerrain(std::make_unique<TerrainDemo>(TERRAIN_SIZE, TERRAIN_SIZE, workspace.systemIterations));
	environment.addAgent(Agent(*workspace.system, TERRAIN_SIZE * 0.5f, TERRAIN_SIZE * 0.5f));

	const auto task = std::make_shared<LRender::Renderer::Task::SceneReport>(
		environment.makeScene(workspace.threadCount, workspace.randomizer),
		workspace.randomizer.makeRandomizer(),
		workspace.threadCount);
	
	console.getMonitor()->makeVisible();
	console.getMonitor()->enqueue(task);
}
