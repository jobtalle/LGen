#pragma once

#include <map>
#include <string>

namespace LGen {
	namespace File {
		class Config {
		public:
			Config();
			Config(const std::string &file);
			virtual ~Config() = default;
			void save(const std::string &file) const;

		protected:
			void set(const std::string &key, const std::string &value);
			const std::string get(const std::string &key) const;

		private:
			static const std::string CONNECTIVE;
			static const std::string CONNECTIVE_FORMATTED;

			std::map<std::string, std::string> pairs;

			void readLine(const std::string &line);
		};
	}
}