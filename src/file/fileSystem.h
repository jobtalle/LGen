#pragma once

#include "lparse.h"
#include "file/fileConfig.h"

#include <string>

namespace LGen {
	namespace File {
		class System final : public Config {
		public:
			System(const std::string &file);
			System(const LParse::System &system);
			LParse::System getSystem() const;

		private:
			static const std::string KEY_AXIOM;
			static const std::string KEY_RULE_COUNT;
			static const std::string KEY_RULE_PREFIX;
		};
	};
}