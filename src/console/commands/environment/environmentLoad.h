#pragma once

#include "console/commands/environment/environment.h"

namespace LGen {
	class Command::Environment::Load final : public Command {
	public:
		Load();

	protected:
		void application(
			const std::vector<std::string> &arguments,
			Console &console) override;

	private:
		static const std::string KEYWORD;
		static const std::string FILE_HELP;
		static const std::string MSG_ERROR;
		static const unsigned char ARG_FILE = 0;
	};
}