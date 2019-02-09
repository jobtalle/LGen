#include "console.h"
#include "commands/exit.h"

#include <iostream>
#include <string>

const std::string L::Console::MSG_NOT_RECOGNIZED = "Command not recognized";

L::Console::Console(L::Monitor *monitor) :
	monitor(monitor) {
	makeCommands();

	thread.reset(new std::thread(std::bind(&L::Console::loop, this)));
}

L::Console::~Console() {
	thread->join();

	for(auto command : commands)
		delete command;
}

void L::Console::stop() {
	terminate = true;

	monitor->stop();
}

void L::Console::loop() {
	while(!terminate) {
		std::string input;
		std::getline(std::cin, input);

		for(auto command : commands)
			if(command->apply(Input(input)))
				goto next;

		std::cout << MSG_NOT_RECOGNIZED << std::endl;

	next:;
	}
}

void L::Console::makeCommands() {
	commands.push_back(new Command::Exit(this));
}