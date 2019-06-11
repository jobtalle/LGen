#pragma once

#include "console/commands/environment/terrain/environmentTerrain.h"

namespace LGen {
	class Command::Environment::Terrain::Flat final : public Command {
	public:
		Flat();

	protected:
		void application(
			const std::vector<std::string> &arguments,
			Console &console) override;

	private:
		static const std::string KEYWORD;
		static const std::string FILE_HELP;
		static const unsigned char ARG_WIDTH = 0;
		static const unsigned char ARG_HEIGHT = 1;
	};
}