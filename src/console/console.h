#pragma once

#include "monitor/monitor.h"

#include <thread>
#include <memory>
#include <vector>

namespace LGen {
	class Command;
	class Console {
	public:
		Console(LGen::Monitor *monitor);
		~Console();
		void stop();
		void dumpFile(const std::string file, const bool prefix = true) const;
		void log(const std::string message, const bool prefix = true) const;

	private:
		static const size_t LINE_WIDTH = 80;
		static const std::string MSG_NOT_RECOGNIZED;
		static const std::string FILE_INTRO;
		static const std::string PREFIX_COMMAND;
		static const std::string PREFIX_LOG;

		std::vector<Command*> commands;
		LGen::Monitor *monitor;
		std::unique_ptr<std::thread> thread;
		bool terminate = false;

		void loop();
		void makeCommands();
	};
}