#include "NeoSed.hpp"
#include <cstddef>


NeoSed::NeoSed(const std::string file_name) : file_name_(file_name) {
	out_file_name = file_name + ".replace";
}

NeoSed::~NeoSed() {

}

void NeoSed::setSearchPattern(const std::string old_pattern) {
	search_pattern_ = old_pattern;
}

void NeoSed::setReplacePattern(const std::string new_pattern) {
	replace_pattern_ = new_pattern;
}

void NeoSed::setSearchPatternLen(const std::string old_pattern) {
	search_pattern_len_ = old_pattern.length();
}

const std::string NeoSed::getSearchPattern() const {
	return (search_pattern_);
}

const std::string NeoSed::getReplacePattern() const {
	return (replace_pattern_);
}

size_t NeoSed::getSearchPatternLen() const {
	return (search_pattern_len_);
}

void NeoSed::setData(const std::string old_pattern, const std::string new_pattern) {
	setSearchPattern(old_pattern);
	setSearchPatternLen(old_pattern);
	setReplacePattern(new_pattern);
}

size_t	NeoSed::searchAndReplace() {
	std::string line;

	std::ifstream file_in(file_name_);
	if (!file_in.is_open()) {
		std::cerr << "error to open for read baby" << std::endl;
		return (1);
	}
	std::ofstream file_out(out_file_name);
	if (!file_out.is_open()) {
		std::cerr << "error to open for write baby" << std::endl;
		return (1);
	}

	while (std::getline(file_in, line)) {
		size_t pos = 0;
		while (true) {
			pos = line.find(getSearchPattern(), pos);
			if (pos == std::string::npos)
				break;
			line.erase(pos, getSearchPatternLen());
			line.insert(pos, getReplacePattern());
			pos += getReplacePattern().length();
			if (getSearchPatternLen() == 0 && getReplacePattern().length() == 0)
                pos++;
		}
		file_out << line << "\n";
	}

	file_in.close();
	file_out.close();
	return (0);
}
