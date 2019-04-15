#pragma once

#include "console/command.h"

namespace LGen {
	class Command::Threads final : public Command {
	public:
		Threads();

	protected:
		void application(
			const std::vector<std::string> &arguments,
			Console &console) override;

	private:
		static const std::string KEYWORD;
		static const std::string FILE_HELP;
		static const std::string MSG_SIM_RUNS_ON;
		static const std::string MSG_THREADS;
		static const std::string MSG_ERROR_RANGE;
		static const std::string ARG_AUTO;
		static const std::string MSG_NO_AUTO;
		static const size_t THREADS_MIN = 1;
		static const size_t THREADS_MAX = 0xFFFF;
		static const unsigned char ARG_THREADS = 0;
	};
}