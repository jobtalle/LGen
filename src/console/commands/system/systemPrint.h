#pragma once

#include "console/commands/system.h"

namespace LGen {
	class Command::System::Print final : public Command {
	public:
		Print();

	protected:
		void application(
			const std::vector<std::string> arguments,
			Console &console,
			Workspace &workspace) override;

	private:
		static const std::string KEYWORD;
		static const std::string FILE;
		static const std::string MSG_AXIOM;
		static const std::string MSG_RULES;
		static const std::string MSG_ITERATIONS;
		static const std::string PREFIX_RULE;
	};
};