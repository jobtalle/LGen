#pragma once

#include "console/commands/system.h"

namespace LGen {
	class Command::System::Rule final : public Command {
	public:
		Rule();

		class Add;
		class Remove;

	private:
		static const std::string KEYWORD;
		static const std::string ALIAS;
	};
};