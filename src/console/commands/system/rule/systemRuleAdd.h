#pragma once

#include "console/commands/system/rule/systemRule.h"

namespace LGen {
	class Command::System::Rule::Add final : public Command {
	public:
		Add();

	protected:
		void application(
			const std::vector<std::string> arguments,
			Console &console,
			Workspace &workspace) override;

	private:
		static const std::string KEYWORD;
		static const std::string FILE_HELP;
		static const unsigned char ARG_LHS = 0;
		static const unsigned char ARG_RHS = 1;
	};
};