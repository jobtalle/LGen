#pragma once

#include "console/command.h"

namespace LGen {
	class Command::Help final : public Command {
	public:
		Help();

	protected:
		void application(
			const std::vector<std::string> &arguments,
			Console &console) override;

	private:
		static const std::string KEYWORD;
		static const std::string ALIAS;
		static const std::string FILE;
	};
}