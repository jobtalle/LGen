#pragma once

#include "console/commands/system/system.h"

namespace LGen {
	class Command::System::Generate final : public Command {
	public:
		Generate();

	protected:
		void application(
			const std::vector<std::string> arguments,
			Console &console,
			Workspace &workspace) override;

	private:
		static const std::string KEYWORD;
		static const std::string ALIAS;
		static const std::string FILE_HELP;
	};
}