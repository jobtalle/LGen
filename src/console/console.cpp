#include "console/console.h"
#include "console/commands/exit.h"
#include "console/commands/help.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace LGen;

const std::string Console::MSG_NOT_RECOGNIZED = "Command not recognized.";
const std::string Console::FILE_INTRO = "text/intro.txt";
const std::string Console::PREFIX_COMMAND = ">> ";
const std::string Console::PREFIX_LOG = "   ";

Console::Console(Monitor *monitor) :
	monitor(monitor),
	commandList(makeCommands(this)) {
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
		log(line, prefix);

	source.close();
}

void Console::log(const std::string message, const bool prefix) const {
	std::string remainder = message;
	std::vector<std::string> lines;

	while(remainder.size() > LINE_WIDTH) {
		lines.push_back(remainder.substr(0, LINE_WIDTH));

		remainder = remainder.substr(LINE_WIDTH, remainder.size());
	}

	lines.push_back(remainder);

	for(const std::string line : lines) {
		if(prefix)
			std::cout << PREFIX_LOG << line << std::endl;
		else
			std::cout << line << std::endl;
	}
}

const CommandList &Console::getCommandList() const {
	return commandList;
}

std::vector<Command*> Console::makeCommands(Console *console) {
	std::vector<Command*> commands;

	commands.push_back(new Command::Exit(console));
	commands.push_back(new Command::Help(console));

	return commands;
}

void Console::loop() {
	while(!terminate) {
		std::cout << PREFIX_COMMAND;

		std::string input;
		std::getline(std::cin, input);

		if(commandList.apply(Input(input)))
			goto next;

		log(MSG_NOT_RECOGNIZED);

	next:;
	}
}