#include "fileEnvironment.h"

#include <sstream>

using namespace LGen::File;

const std::string Environment::KEY_MAX_ITERATIONS = "max-iterations";

Environment::Environment(const std::string &file) :
	Config(file) {

}

Environment::Environment(const LGen::Environment &environment) {
	std::stringstream maxIterations;

	maxIterations << environment.getMaxIterations();

	set(KEY_MAX_ITERATIONS, maxIterations.str());
}

LGen::Environment Environment::getEnvironment() const {
	LGen::Environment environment;

	environment.setMaxIterations(std::stoi(get(KEY_MAX_ITERATIONS)));

	return environment;
}