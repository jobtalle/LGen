#pragma once

#include <map>
#include <string>
#include <istream>
#include <ostream>

namespace LGen {
	namespace File {
		class Config {
		public:
			Config();
			Config(const std::istream &file);
			void serialize(const std::ostream &file) const;

		protected:
			void set(const std::string &key, const std::string &value);
			const std::string &get(const std::string &key) const;

		private:
			static const std::string CONNECTIVE;

			std::map<std::string, std::string> pairs;
		};
	}
};