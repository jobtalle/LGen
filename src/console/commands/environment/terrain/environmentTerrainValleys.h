#pragma once

#include "console/commands/environment/terrain/environmentTerrain.h"

namespace LGen {
	class Command::Environment::Terrain::Valleys final : public Command {
	public:
		Valleys();

	protected:
		void application(
			const std::vector<std::string> &arguments,
			Console &console) override;

	private:
		static const std::string KEYWORD;
		static const std::string FILE_HELP;
		static const unsigned char ARG_WIDTH = 0;
		static const unsigned char ARG_HEIGHT = 1;
		static const unsigned char ARG_RESOLUTION = 2;
	};
}