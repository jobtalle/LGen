#include "environmentTerrainDropwave.h"
#include "environment/terrain/terrainDropwave.h"

using namespace LGen;

const std::string Command::Environment::Terrain::Dropwave::KEYWORD = "dropwave";
const std::string Command::Environment::Terrain::Dropwave::FILE_HELP = "text/helpEnvironmentTerrainDropwave.txt";

Command::Environment::Terrain::Dropwave::Dropwave() :
	Command({ KEYWORD }, FILE_HELP, 3) {

}

void Command::Environment::Terrain::Dropwave::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.environment) {
		console << MSG_NO_ENVIRONMENT << std::endl;

		return;
	}

	try {
		const auto width = std::stof(arguments[ARG_WIDTH]);
		const auto height = std::stof(arguments[ARG_HEIGHT]);
		const auto period = std::stof(arguments[ARG_PERIOD]);

		workspace.environment->setTerrain(std::make_unique<TerrainDropwave>(width, height, period));
	}
	catch(...) {
		console << MSG_INVALID_INPUT << std::endl;
	}
}
