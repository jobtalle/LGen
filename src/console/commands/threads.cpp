#include "threads.h"

#include <thread>

using namespace LGen;

const std::string Command::Threads::KEYWORD = "threads";
const std::string Command::Threads::FILE_HELP = "text/helpThreads.txt";
const std::string Command::Threads::MSG_SIM_RUNS_ON = "The simulation will run on ";
const std::string Command::Threads::MSG_THREADS = " threads.";
const std::string Command::Threads::MSG_ERROR_RANGE = "Please give a number in the range ";
const std::string Command::Threads::ARG_AUTO = "auto";
const std::string Command::Threads::MSG_NO_AUTO = "No automatic thread count can be inferred.";

Command::Threads::Threads() :
	Command({ KEYWORD }, FILE_HELP, 1) {
	
}

void Command::Threads::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	try {
		const size_t threads = std::stoi(arguments[ARG_THREADS]);

		if(threads >= THREADS_MIN && threads <= THREADS_MAX) {
			workspace.threadCount = threads;

			console << MSG_SIM_RUNS_ON << threads << MSG_THREADS << std::endl;
		}
		else
			console << MSG_ERROR_RANGE << '[' << THREADS_MIN << ", " << THREADS_MAX << ']' << std::endl;
	}
	catch(...) {
		if(arguments[ARG_THREADS] == ARG_AUTO) {
			const size_t threads = std::thread::hardware_concurrency();

			if(threads == 0)
				console << MSG_NO_AUTO << std::endl;
			else {
				workspace.threadCount = threads;

				console << MSG_SIM_RUNS_ON << threads << MSG_THREADS << std::endl;
			}
		}
		else
			console << MSG_INVALID_INPUT << std::endl;
	}
}
