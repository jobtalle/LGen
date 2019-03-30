#include "fileEnvironment.h"
#include "fileTerrain.h"
#include "fileSystem.h"
#include "file.h"

using namespace LGen;

static const std::string KEY_MAX_ITERATIONS = "max-iterations";
static const std::string KEY_TERRAIN = "terrain";
static const std::string KEY_AGENT_PREFIX = "agent-";
static const std::string KEY_AGENT_SYSTEM = "system";
static const std::string KEY_AGENT_X = "x";
static const std::string KEY_AGENT_Y = "y";

File &LGen::operator<<(File& file, const Environment &environment) {
	auto fileTerrain = File();
	
	fileTerrain << environment.getTerrain();

	file.set(KEY_MAX_ITERATIONS, static_cast<int>(environment.getMaxIterations()));
	file.set(KEY_TERRAIN, fileTerrain);

	for(size_t i = 0; i < environment.getAgents().size(); ++i) {
		const auto &agent = environment.getAgents()[i];
		File fileAgent;
		File fileSystem;

		fileSystem << agent.getSystem();

		fileAgent.set(KEY_AGENT_SYSTEM, fileSystem);
		fileAgent.set(KEY_AGENT_X, agent.getX());
		fileAgent.set(KEY_AGENT_Y, agent.getY());

		file.set(KEY_AGENT_PREFIX + std::to_string(i), fileAgent);
	}

	return file;
}

std::unique_ptr<Environment> &LGen::operator<<(std::unique_ptr<Environment> &environment, const File &file) {
	environment = std::make_unique<Environment>();
	
	std::unique_ptr<Terrain> terrain;

	environment->setMaxIterations(file.getInt(KEY_MAX_ITERATIONS));
	environment->setTerrain(std::move(terrain << file.getFile(KEY_TERRAIN)));

	std::string key;
	size_t i = 0;

	while(key = KEY_AGENT_PREFIX + std::to_string(i++), file.keyExists(key)) {
		const auto &fileAgent = file.getFile(key);
		const auto &fileSystem = fileAgent.getFile(KEY_AGENT_SYSTEM);
		const auto x = fileAgent.getFloat(KEY_AGENT_X);
		const auto y = fileAgent.getFloat(KEY_AGENT_Y);
		std::unique_ptr<LParse::System> system;

		environment->addAgent(Agent(*(system << fileSystem), x, y));
	}

	return environment;
}
