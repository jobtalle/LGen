#pragma once

#include <map>
#include <string>
#include <vector>
#include <ostream>

namespace LGen {
	class File final {
	public:
		File() = default;
		File(const std::string &file);
		File(std::vector<std::string>::const_iterator &line);
		virtual ~File() = default;
		void save(const std::string &file) const;
		void printValues(std::ostream &stream, const std::string &indent = "") const;
		void printFiles(std::ostream &stream, const std::string &indent = "") const;
		void set(const std::string &key, const std::string &value);
		void set(const std::string &key, const File &file);
		void get(const std::string &key, std::string &value) const;
		void get(const std::string &key, File &file) const;

	private:
		static const std::string CONNECTIVE;
		static const std::string CONNECTIVE_FORMATTED;
		static const std::string BLOCK_START;
		static const std::string BLOCK_CLOSE;
		static const std::string INDENT;

		std::map<std::string, std::string> values;
		std::map<std::string, File> files;

		void read(std::vector<std::string>::const_iterator &line);
	};
}

std::ostream &operator<<(std::ostream &stream, const LGen::File &file);
