#include "pch.h"
#include <string>

size_t Text::size()
{
	return glyphs.size() - 1;
}

const char* Text::operator & (const char* suffix)
{
	/*
	std::string result = glyphs.data();
	result += suffix;
	return result.c_str();
	*/
	//^ need to allocate outside of function if used

	size_t length = 1 + strlen(suffix) + glyphs.size();
	char* newS = (char*)malloc(length * sizeof(char));
	strcpy(newS, glyphs.data());
	strcat(newS, suffix);
	return newS;
}   // TODO has to be freed manually after function

const char* Text::share()
{
	return glyphs.data();
}

const char* Text::add(const char* suffix)
{
	glyphs.pop_back();
	glyphs.insert(glyphs.end(), suffix, suffix + std::strlen(suffix));
	glyphs.push_back('\0');
	return glyphs.data();
}

bool Text::pop(size_t count) {
	if (glyphs.size() == 0) {
		return false;
	}
	glyphs.pop_back();

	while (count > 0) {
		glyphs.pop_back();
		if (glyphs.size() == 0) {
			glyphs.push_back('\0');
			return false;
		}
		--count;
	}
	glyphs.push_back('\0');
	return true;
}