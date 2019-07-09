#pragma once
#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <map>
#include <vector>
#include <regex>

using namespace std;

struct asciiArtLetter
{
	vector <string> lines;
	size_t letterWidth;
};

class Dictionary
{
public:
	map<const char, asciiArtLetter> readCharToAsciiArtDictionary();
};
