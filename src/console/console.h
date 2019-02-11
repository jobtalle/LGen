#pragma once

#include "monitor/monitor.h"
#include "console/commandList.h"
#include "workspace/workspace.h"

#include <thread>
#include <memory>
#include <vector>

namespace LGen {
	class Command;
	class Console {
	public:
		Console(Monitor *monitor, Workspace *workspace);
		~Console();
		void stop();
		void dumpFile(const std::string file, const bool prefix = true) const;
		void log(const std::string message, const bool prefix = true) const;
		const CommandList &getCommandList() const;

	private:
		static const size_t LINE_WIDTH = 80;
		static const std::string MSG_NOT_RECOGNIZED;
		static const std::string FILE_INTRO;
		static const std::string PREFIX_COMMAND;
		static const std::string PREFIX_LOG;

		const CommandList commandList;
		Monitor *monitor;
		Workspace *workspace;
		std::unique_ptr<std::thread> thread;
		bool terminate = false;

		static std::vector<Command*> makeCommands(Console *console);

		void loop();
	};
}