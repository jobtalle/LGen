#include "systemExposure.h"
#include "environment/terrain/terrainFlat.h"
#include "lrender.h"

using namespace LGen;

const std::string Command::System::Exposure::KEYWORD = "exposure";
const std::string Command::System::Exposure::ALIAS = "exp";
const std::string Command::System::Exposure::FILE_HELP = "text/helpSystemExposure.txt";

Command::System::Exposure::Exposure() :
	Command({ KEYWORD, ALIAS }, FILE_HELP, 0) {
	
}

void Command::System::Exposure::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.system) {
		console << MSG_NO_SYSTEM << std::endl;

		return;
	}

	LGen::Environment environment;

	environment.setTerrain(std::make_unique<TerrainFlat>(20.0f, 20.0f));
	environment.addAgent(Agent(*workspace.system, 3, 3));
	environment.addAgent(Agent(*workspace.system, 6, 3));
	environment.addAgent(Agent(*workspace.system, 6, 6));
	environment.addAgent(Agent(*workspace.system, 3, 6));

	auto task = std::make_shared<LRender::Renderer::Task::Exposure>(
		environment.makeScene(workspace.randomizer),
		workspace.randomizer.makeRandomizer(),
		workspace.threadCount);

	console.getMonitor()->makeVisible();
	console.getMonitor()->enqueue(task);
}
