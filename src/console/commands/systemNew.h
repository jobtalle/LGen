#pragma once

#include "console/commands/system.h"

namespace LGen {
	class Command::System::New final : public Command {
	public:
		New();

	private:
		static const std::string KEYWORD;
		static const std::string FILE;
	};
};