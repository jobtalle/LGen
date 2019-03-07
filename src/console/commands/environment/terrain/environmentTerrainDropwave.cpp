#include "environmentTerrainDropwave.h"
#include "environment/terrain/terrainDropwave.h"

using namespace LGen;

const std::string Command::Environment::Terrain::Dropwave::KEYWORD = "dropwave";
const std::string Command::Environment::Terrain::Dropwave::FILE_HELP = "text/helpEnvironmentTerrainDropwave.txt";

Command::Environment::Terrain::Dropwave::Dropwave() :
	Command({ KEYWORD }, FILE_HELP, 0) {

}

void Command::Environment::Terrain::Dropwave::application(
	const std::vector<std::string> arguments,
	Console &console) {
	if(!workspace.environment) {
		console << MSG_NO_ENVIRONMENT << std::endl;

		return;
	}

	workspace.environment->setTerrain(std::make_shared<TerrainDropwave>(20, 20));
}