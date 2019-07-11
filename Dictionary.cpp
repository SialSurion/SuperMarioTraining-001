#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <streambuf>
#include <regex>
#include <windows.h>

Dictionary::Dictionary(void)
{
	ifstream infile("alphabet.txt");

	string infile_str((istreambuf_iterator<char>(infile)), istreambuf_iterator<char>());

	regex e("([a-zA-Z0-9])\n(.*)\n(.*)\n(.*)\n(.*)\n(.*)\n");

	sregex_iterator iter(infile_str.begin(), infile_str.end(), e);
	sregex_iterator end;

	while (iter != end)
	{
		asciiLetter = {};

		strncpy(letter, (*iter)[1].str().c_str(), 1);

		for (unsigned i = 2; i < iter->size(); ++i)
		{
			asciiLetter.lines.push_back((*iter)[i].str());
		}

		setLetterWidth(asciiLetter);
		resizeLetterLines(asciiLetter);

		dictionary.emplace(*letter, asciiLetter);

		++iter;
	}

	insertSpaceToDictionary();
}

void Dictionary::setLetterWidth(asciiArtLetter& asciiLetter)
{
	size_t width = 0;
	for (auto& line : asciiLetter.lines)
	{
		// Remove trailing spaces -> line = regex_replace(line, regex(" +$"), "");
		if (width < line.size())
		{
			width = line.size();
		}
	}
	asciiLetter.letterWidth = width;
}

void Dictionary::resizeLetterLines(asciiArtLetter& asciiLetter)
{
	for (auto& line : asciiLetter.lines)
	{
		line.resize(asciiLetter.letterWidth, ' ');
	}
}

void Dictionary::insertSpaceToDictionary()
{
	asciiLetter.lines = vector<string>(5, " ");
	asciiLetter.letterWidth = 1;

	dictionary.emplace(' ', asciiLetter);
}

bool Dictionary::testTextVsConsoleWidth(string& textToPrint)
{
	bool result = false;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	auto largestConsole = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));

	size_t textWidth = 0;
	for (auto& letter : textToPrint)
	{
		textWidth += dictionary[letter].letterWidth;
	}

	if (static_cast<int>(textWidth) <= columns)
	{
		result = true;
	}
	else if (largestConsole.X - 2 >= static_cast<int>(textWidth))
	{
		SetConsoleWindow(textWidth + 2, rows);
		result = true;
	}
	
	return result;
}

void Dictionary::printAsciiArt(string& textToPrint)
{
	if (regex_match(textToPrint, regex("[^a-zA-Z0-9 ]")))
	{
		cout << "error - wrong character" << endl;
	}
	else if (!testTextVsConsoleWidth(textToPrint))
	{
		cout << "error - too long text" << endl;
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			for (auto& letter : textToPrint)
			{
				cout << dictionary[letter].lines[i];
			}
			cout << endl;
		}
	}
}

void Dictionary::SetConsoleWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
}