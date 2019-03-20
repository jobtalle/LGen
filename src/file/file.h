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
		void save(const std::string &file) const;
		void printValues(std::ostream &stream, const std::string &indent = "") const;
		void printFiles(std::ostream &stream, const std::string &indent = "") const;

		bool keyExists(const std::string &key) const;

		void set(const std::string &key, const std::string &value);
		void set(const std::string &key, const float value);
		void set(const std::string &key, const int value);
		void set(const std::string &key, const File &file);

		std::string getString(const std::string &key) const;
		float getFloat(const std::string &key) const;
		int getInt(const std::string &key) const;
		File getFile(const std::string &key) const;

	private:
		static const std::string CONNECTIVE;
		static const std::string CONNECTIVE_FORMATTED;
		static const std::string INDENT;
		static const std::string BLOCK_START;
		static const std::string BLOCK_CLOSE;

		std::map<std::string, std::string> values;
		std::map<std::string, File> files;

		void read(std::vector<std::string>::const_iterator &line);
	};
}

std::ostream &operator<<(std::ostream &stream, const LGen::File &file);
