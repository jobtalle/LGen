#pragma once

#include "console/commands/environment/environment.h"

namespace LGen {
	class Command::Environment::Initialize final : public Command {
	public:
		Initialize();

	protected:
		void application(
			const std::vector<std::string> &arguments,
			Console &console) override;

	private:
		static const std::string KEYWORD;
		static const std::string ALIAS;
		static const std::string FILE_HELP;
		static const std::string MSG_NO_SYSTEM;
		static const char ARG_SPACING = 0;
	};
}