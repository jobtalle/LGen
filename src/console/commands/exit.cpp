#include "exit.h"

#include <iostream>

LGen::Command::Exit::Exit(Console *console) :
	Command({ "exit" }),
	console(console) {

}

void LGen::Command::Exit::application(const std::vector<std::string> arguments) {
	console->stop();
}