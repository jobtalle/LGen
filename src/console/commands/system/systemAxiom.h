#pragma once

#include "console/commands/system.h"

namespace LGen {
	class Command::System::Axiom final : public Command {
	public:
		Axiom();

	protected:
		void application(
			const std::vector<std::string> arguments,
			Console &console,
			Workspace &workspace) override;

	private:
		static const std::string KEYWORD;
		static const std::string ALIAS;
		static const std::string FILE_HELP;
		static const unsigned char ARG_SENTENCE = 0;
	};
};