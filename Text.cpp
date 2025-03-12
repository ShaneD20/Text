#include "text.h"

size_t Text::size()
{
	return glyphs.size() - 1;
}

const char* Text::operator & (const char* suffix)
{
	std::vector<char> output = glyphs;
	output.pop_back();
	output.insert(output.end(), suffix, suffix + std::strlen(suffix));
	output.push_back('\0');
	return output.data();
}

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