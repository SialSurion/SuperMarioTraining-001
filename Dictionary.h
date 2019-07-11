#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;

struct asciiArtLetter
{
	vector <string> lines;
	size_t letterWidth;
};

class Dictionary
{
public:
	Dictionary(void);
	void printAsciiArt(string& textToTransform);

private:
	char* letter = new char();
	asciiArtLetter asciiLetter;
	map<char, asciiArtLetter> dictionary;

	void setLetterWidth(asciiArtLetter& asciiLetter);
	void resizeLetterLines(asciiArtLetter& asciiLetter);
	void insertSpaceToDictionary();
	bool testTextVsConsoleWidth(string& textToPrint);
	void SetConsoleWindow(int Width, int Height);
};
