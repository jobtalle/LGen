#pragma once

#include "lparse.h"
#include "file/file.h"

#include <string>

namespace LGen {
	class FileSystem final {
	public:
		static File serialize(const LParse::System &system);
		static LParse::System deserialize(const File &file);

	private:
		static const std::string KEY_AXIOM;
		static const std::string KEY_RULE_PREFIX;
	};
}
