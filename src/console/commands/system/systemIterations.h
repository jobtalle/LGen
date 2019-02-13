#pragma once

#include "console/commands/system.h"

namespace LGen {
	class Command::System::Iterations final : public Command {
	public:
		Iterations();

	protected:
		void application(
			const std::vector<std::string> arguments,
			Console &console,
			Workspace &workspace) override;

	private:
		static const std::string KEYWORD;
		static const std::string FILE_HELP;
	};
};