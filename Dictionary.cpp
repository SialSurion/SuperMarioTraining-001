#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <streambuf>
#include <regex>


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

void Dictionary::printAsciiArt(string& textToPrint)
{
	for (int i = 0; i < 5; i++)
	{
		for (auto& letter : textToPrint)
		{
			if (regex_match(string(1, letter), regex("[a-zA-Z0-9]")))
			{
				cout << dictionary[letter].lines[i];
			}
			else if (letter == ' ')
			{
				cout << " ";
			}
			else
			{
				cout << "error - wrong character" ;
			}
		}
		cout << endl;
	}
}