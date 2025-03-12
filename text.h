#include <vector>

struct Text
{
private:
	std::vector<char> glyphs{};
public:
	Text(const char* values)
	{
		glyphs.insert(glyphs.end(), values, values + std::strlen(values));
		glyphs.push_back('\0');
	}
	~Text()
	{}

	size_t size();
	const char* operator & (const char* values);
	const char* add(const char* suffix);
	const char* share();
};