#pragma once

#include "console/commands/system/system.h"

namespace LGen {
	class Command::System::Load final : public Command {
	public:
		Load();

	protected:
		void application(
			const std::vector<std::string> arguments,
			Console &console,
			Workspace &workspace) override;

	private:
		static const std::string KEYWORD;
		static const std::string FILE_HELP;
		static const std::string MSG_ERROR;
		static const unsigned char ARG_FILE = 0;
	};
};