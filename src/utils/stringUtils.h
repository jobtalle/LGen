#pragma once

#include <string>

namespace LGen {
	namespace Utils {
		class String final {
		public:
			static std::string ltrim(const std::string &string);
			static std::string rtrim(const std::string &string);
			static std::string trim(const std::string &string);
			static void split(
				const std::string &string,
				const std::string &split,
				std::string &lhs,
				std::string &rhs);

		protected:
			String() = default;

		private:
			static const std::string WHITESPACES;
		};
	}
};