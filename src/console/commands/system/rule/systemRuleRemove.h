#pragma once

#include "console/commands/system/rule/systemRule.h"

namespace LGen {
	class Command::System::Rule::Remove final : public Command {
	public:
		Remove();

	protected:
		void application(
			const std::vector<std::string> arguments,
			Console &console) override;

	private:
		static const std::string KEYWORD;
		static const std::string FILE_HELP;
		static const std::string MSG_RULE_DOES_NOT_EXIST;
		static const unsigned char ARG_LHS = 0;
		static const unsigned char ARG_RHS = 1;
	};
}