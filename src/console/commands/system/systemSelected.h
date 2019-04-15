#pragma once

#include "console/commands/system/system.h"

namespace LGen {
	class Command::System::Selected final : public Command {
	public:
		Selected();

	protected:
		void application(
			const std::vector<std::string> &arguments,
			Console &console) override;

	private:
		static const std::string KEYWORD;
		static const std::string FILE_HELP;
		static const std::string MSG_ERROR;
	};
}