#pragma once
#ifndef NEOSED_H
# define NEOSED_H
# include <iostream>
# include <string>
# include <fstream>

class NeoSed {
	public:
		NeoSed(const std::string file_name);
		~NeoSed();

		void setData(const std::string old_pattern, const std::string new_pattern);

		const std::string getSearchPattern() const;
		const std::string getReplacePattern() const;
		size_t getSearchPatternLen() const;

		size_t	searchAndReplace();

	private:
		std::string file_name_;
		std::string out_file_name;
		std::string search_pattern_;
		std::string replace_pattern_;
		size_t search_pattern_len_;

		void setSearchPattern(const std::string old_pattern);
		void setReplacePattern(const std::string new_pattern);
		void setSearchPatternLen(const std::string old_pattern);
};


#endif
