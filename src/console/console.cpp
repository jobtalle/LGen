#include "console/console.h"
#include "console/commands/exit.h"
#include "console/commands/help.h"
#include "console/commands/system/system.h"
#include "console/commands/render/render.h"
#include "console/commands/environment/environment.h"
#include "console/commands/simulation/simulation.h"
#include "console/commands/threads.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace LGen;

const std::string Console::MSG_NOT_RECOGNIZED = "Command not recognized.\n";
const std::string Console::FILE_INTRO = "text/intro.txt";
const std::string Console::PREFIX_COMMAND = ">> ";
const std::string Console::PREFIX_LOG = "   ";

Console::Console(Monitor *const monitor) :
	std::ostream(this),
	commandList({
		std::make_unique<Command::Exit>(this),
		std::make_unique<Command::Help>(),
		std::make_unique<Command::System>(),
		std::make_unique<Command::Render>(),
		std::make_unique<Command::Environment>(),
		std::make_unique<Command::Simulation>(),
		std::make_unique<Command::Threads>()
	}),
	monitor(monitor) {
	dumpFile("text/intro.txt", false);

	thread = std::make_unique<std::thread>(std::bind(&Console::loop, this));
}

Console::~Console() {
	thread->join();
}

Monitor *Console::getMonitor() const {
	return monitor;
}

void Console::stop() {
	terminate = true;

	monitor->stop();
}

void Console::dumpFile(const std::string file, const bool prefix) const {
	std::ifstream source;
	std::string line;

	source.open(file);

	while(std::getline(source, line))
		log(line, prefix), log("\n");

	source.close();
}

const CommandList &Console::getCommandList() const {
	return commandList;
}

std::streambuf::int_type Console::overflow(std::streambuf::int_type c) {
	line += char(c);

	return c;
}

int Console::sync() {
	log(line);
	line.clear();

	return 0;
}

void Console::log(const std::string& message, const bool prefix) {
	const size_t width = prefix ? LINE_WIDTH - PREFIX_LOG.size() : LINE_WIDTH;
	std::string remainder = message;
	std::vector<std::string> lines;

	while(remainder.size() > width) {
		size_t trimAt = width;
		size_t resumeAt = trimAt;
		size_t lastSpace = remainder.find_last_of(" ", width);

		if(lastSpace != std::string::npos) {
			trimAt = lastSpace;
			resumeAt = trimAt + 1;
		}

		lines.push_back(remainder.substr(0, trimAt) + '\n');
		remainder = remainder.substr(resumeAt, remainder.size());
	}

	lines.push_back(remainder);

	for(const std::string &line : lines) {
		if(prefix)
			std::cout << PREFIX_LOG << line;
		else
			std::cout << line;
	}
}

void Console::loop() {
	while(!terminate) {
		std::cout << PREFIX_COMMAND;

		std::string input;
		std::getline(std::cin, input);

		if(!commandList.apply(Input(input), *this))
			log(MSG_NOT_RECOGNIZED);
	}
}
