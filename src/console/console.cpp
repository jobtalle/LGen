#include "console.h"
#include "commands/exit.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace LGen;

const std::string Console::MSG_NOT_RECOGNIZED = "Command not recognized.";
const std::string Console::FILE_INTRO = "text/intro.txt";
const std::string Console::COMMAND_PREFIX = ">> ";

Console::Console(Monitor *monitor) :
	monitor(monitor) {
	makeCommands();

	dumpFile("text/intro.txt");

	thread.reset(new std::thread(std::bind(&Console::loop, this)));
}

Console::~Console() {
	thread->join();

	for(auto command : commands)
		delete command;
}

void Console::stop() {
	terminate = true;

	monitor->stop();
}

void Console::dumpFile(const std::string file) {
	std::ifstream source;
	std::string line;

	source.open(file);

	while(std::getline(source, line))
		std::cout << line << std::endl;

	source.close();
}

void Console::loop() {
	while(!terminate) {
		std::cout << COMMAND_PREFIX;

		std::string input;
		std::getline(std::cin, input);

		for(auto command : commands)
			if(command->apply(Input(input)))
				goto next;

		std::cout << MSG_NOT_RECOGNIZED << std::endl;

	next:;
	}
}

void Console::makeCommands() {
	commands.push_back(new Command::Exit(this));
}