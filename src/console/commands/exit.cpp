#include "exit.h"

#include <iostream>

using namespace LGen;

Command::Exit::Exit(Console *console) :
	Command({ "exit" }),
	console(console) {

}

void Command::Exit::application(const std::vector<std::string> arguments) {
	console->stop();
}