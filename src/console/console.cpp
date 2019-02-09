#include "console.h"
#include "commands/exit.h"

#include <iostream>
#include <string>
#include <fstream>

const std::string LGen::Console::MSG_NOT_RECOGNIZED = "Command not recognized";
const std::string LGen::Console::FILE_INTRO = "text/intro.txt";
const std::string LGen::Console::COMMAND_PREFIX = ">> ";

LGen::Console::Console(LGen::Monitor *monitor) :
	monitor(monitor) {
	makeCommands();

	dumpFile("text/intro.txt");

	thread.reset(new std::thread(std::bind(&LGen::Console::loop, this)));
}

LGen::Console::~Console() {
	thread->join();

	for(auto command : commands)
		delete command;
}

void LGen::Console::stop() {
	terminate = true;

	monitor->stop();
}

void LGen::Console::dumpFile(const std::string file) {
	std::ifstream source;
	std::string line;

	source.open(file);

	while(std::getline(source, line))
		std::cout << line << std::endl;

	source.close();
}

void LGen::Console::loop() {
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

void LGen::Console::makeCommands() {
	commands.push_back(new Command::Exit(this));
}