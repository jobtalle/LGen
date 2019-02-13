#pragma once

#include "monitor/monitor.h"
#include "console/commandList.h"
#include "workspace/workspace.h"

#include <thread>
#include <memory>
#include <vector>
#include <ostream>
#include <sstream>
#include <string>

namespace LGen {
	class Command;
	class Console final : private std::streambuf, public std::ostream {
	public:
		Console(Monitor *monitor, Workspace *workspace);
		~Console();
		void stop();
		void dumpFile(const std::string file, const bool prefix = true) const;
		const CommandList &getCommandList() const;
		std::streambuf::int_type overflow(std::streambuf::int_type c) override;
		int sync() override;

	private:
		static const size_t LINE_WIDTH = 80;
		static const size_t SPACE_SEEK = 24;
		static const std::string MSG_NOT_RECOGNIZED;
		static const std::string FILE_INTRO;
		static const std::string PREFIX_COMMAND;
		static const std::string PREFIX_LOG;

		const CommandList commandList;
		Monitor *monitor;
		Workspace *workspace;
		std::unique_ptr<std::thread> thread;
		bool terminate = false;
		std::string line;

		static std::vector<Command*> makeCommands(Console *console);

		void log(const std::string message, const bool prefix = true) const;
		void loop();
	};
}