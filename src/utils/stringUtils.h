#pragma once

#include <string>

namespace LGen {
	namespace Utils {
		class String final {
		public:
			static std::string ltrim(const std::string &string);
			static std::string rtrim(const std::string &string);
			static std::string trim(const std::string &string);

		protected:
			String() = default;

		private:
			static const std::string WHITESPACES;
		};
	}
};