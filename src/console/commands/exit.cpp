#include "exit.h"

#include <iostream>

L::Command::Exit::Exit(Console *console) :
	Command({ "exit" }),
	console(console) {

}

void L::Command::Exit::application(const std::vector<std::string> arguments) {
	console->stop();
}