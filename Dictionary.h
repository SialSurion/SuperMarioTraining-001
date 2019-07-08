#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct asciiArtLetter
{
	vector <string> lines;
	size_t letterWidth;
};

class Dictionary
{
	/*TODO:
		- Method to read alphabet.txt file as single string
		- Use regex on the string to find all matches of groups containing [key] char and [value] 5 lines of ASCII_ART char representation
		- Save found matches as map<char, struct> where struct is common structure consisted of ASCII art string lines and ASCII ART letter width(bigges line length)
	*/

	/*
		std:string regex = "(?<character>[a-zA-Z0-9])\n(?<asciiArtLine1>.*)\n(?<asciiArtLine2>.*)\n(?<asciiArtLine3>.*)\n(?<asciiArtLine4>.*)\n(?<asciiArtLine5>.*)\n"
	*/
public:
	map<char, asciiArtLetter> readCharToAsciiArtDictionary()
	{
		ifstream infile(".\alphabet.txt");

		map<char, asciiArtLetter> dictionary;

		const char *letter;
		asciiArtLetter asciiLetter;

		unsigned int linesRead = 0;
		string line;
		while (getline(infile, line) && linesRead < 6)
		{
			++linesRead;

			if (linesRead == 1)
			{
				letter = line.c_str();
			}
			else
			{
				asciiLetter.lines.push_back(line);
			}
		}

		//find longest
		size_t width = 0;
		for (auto& line : asciiLetter.lines)
		{
			if (width < line.size())
			{
				width = line.size();
			}
		}

		asciiLetter.letterWidth = width;

		return dictionary;
	}


};
