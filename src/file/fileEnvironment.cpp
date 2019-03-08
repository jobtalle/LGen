#include "fileEnvironment.h"

#include <sstream>

using namespace LGen;

const std::string FileEnvironment::KEY_MAX_ITERATIONS = "max-iterations";

File FileEnvironment::serialize(const Environment &environment) {
	File file;

	file.set(KEY_MAX_ITERATIONS, std::to_string(environment.getMaxIterations()));

	return file;
}

Environment FileEnvironment::deserialize(const File &file) {
	Environment environment;

	std::string maxIterations;

	file.get(KEY_MAX_ITERATIONS, maxIterations);

	environment.setMaxIterations(std::stoi(maxIterations));

	return environment;
}