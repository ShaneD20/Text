#include "pch.h"

size_t Text::size()
{
	return glyphs.size() - 1;
}

const char* Text::operator & (const char* suffix)
{
	size_t length = 1 + strlen(suffix) + glyphs.size();
	char* newS = (char*)malloc(length * sizeof(char));
	strcpy(newS, glyphs.data());
	strcat(newS, suffix);
	return newS;
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