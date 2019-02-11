#pragma once

#include "console/command.h"

namespace LGen {
	class Command::Help final : public Command {
	public:
		Help();

	protected:
		void application(const Console &console, const std::vector<std::string> arguments) override;

	private:
		static const std::string KEYWORD;
		static const std::string ALIAS;
		static const std::string FILE;
	};
}