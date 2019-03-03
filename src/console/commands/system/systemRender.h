#pragma once

#include "console/commands/system/system.h"

namespace LGen {
	class Command::System::Render final : public Command {
	public:
		Render();

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