#pragma once

#include "workspace/workspace.h"
#include "lparse.h"

#include <memory>
#include <ostream>
#include <string>

namespace LGen {
	class Workspace::System final {
	public:
		void create();
		void destroy();
		void print(std::ostream &stream) const;
		
	private:
		static const std::string MSG_SYSTEM_INVALID;

		std::unique_ptr<LParse::System> system;
	};
}