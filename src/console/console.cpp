#include "console/console.h"
#include "console/commands/exit.h"
#include "console/commands/help.h"
#include "console/commands/system.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace LGen;

const std::string Console::MSG_NOT_RECOGNIZED = "Command not recognized.\n";
const std::string Console::FILE_INTRO = "text/intro.txt";
const std::string Console::PREFIX_COMMAND = ">> ";
const std::string Console::PREFIX_LOG = "   ";

Console::Console(Monitor *monitor, Workspace *workspace) :
	monitor(monitor),
	workspace(workspace),
	commandList(makeCommands(this)),
	std::ostream(this) {
	dumpFile("text/intro.txt", false);

	thread.reset(new std::thread(std::bind(&Console::loop, this)));
}

Console::~Console() {
	thread->join();
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

std::vector<Command*> Console::makeCommands(Console *console) {
	std::vector<Command*> commands;

	commands.push_back(new Command::Exit(console));
	commands.push_back(new Command::Help());
	commands.push_back(new Command::System());

	return commands;
}

void Console::log(const std::string message, const bool prefix) const {
	const size_t width = prefix ? LINE_WIDTH - PREFIX_LOG.size() : LINE_WIDTH;
	std::string remainder = message;
	std::vector<std::string> lines;

	while(remainder.size() > width) {
		size_t trimAt = width;
		size_t resumeAt = trimAt;
		size_t lastSpace = remainder.find_last_of(" ", LINE_WIDTH);

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

		if(commandList.apply(Input(input), *this, *workspace))
			goto next;

		log(MSG_NOT_RECOGNIZED);

	next:;
	}
}