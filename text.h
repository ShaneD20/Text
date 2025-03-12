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

	/// <returns>Creates a new C String with the characters stored in Text the provided suffix</returns>
	const char* operator & (const char* values);

	/// <summary>Concatenates the C String stored in text and returns the result</summary>
	const char* add(const char* suffix);

	/// <summary>Shares the current C String stored in Text</summary>
	const char* share();
};