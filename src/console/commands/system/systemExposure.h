#pragma once

#include "console/commands/system/system.h"

namespace LGen {
	class Command::System::Exposure final : public Command {
	public:
		Exposure();

	protected:
		void application(
			const std::vector<std::string> &arguments,
			Console &console) override;

	private:
		static const std::string KEYWORD;
		static const std::string ALIAS;
		static const std::string FILE_HELP;
	};
}