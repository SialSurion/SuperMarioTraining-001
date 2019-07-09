#include "Dictionary.h"

map<const char, asciiArtLetter> Dictionary::readCharToAsciiArtDictionary()
{
	ifstream infile("alphabet.txt");

	string infile_str((istreambuf_iterator<char>(infile)), istreambuf_iterator<char>());

	map<const char, asciiArtLetter> dictionary;

	//Use Regex to find all matches. assign found groups to letters' lines
	regex e("([a-zA-Z0-9])\n(.*)\n(.*)\n(.*)\n(.*)\n(.*)\n");

	//cout << infile_str << endl;

	sregex_iterator iter(infile_str.begin(), infile_str.end(), e);
	sregex_iterator end;

	while (iter != end)
	{
		string letter;
		asciiArtLetter asciiLetter;

		//cout << "size: " << iter->size() << endl;

		//cout << "expression match #" << 0 << ": " << (*iter)[0] << endl;
		for (unsigned i = 2; i < iter->size(); ++i)
		{
			//cout << "capture submatch #" << i << ": " << (*iter)[i] << endl;
			asciiLetter.lines.push_back((*iter)[i].str());
		}

		letter = (*iter)[1].str();

		//find longest line
		size_t width = 0;
		for (auto& line : asciiLetter.lines)
		{
			if (width < line.size())
			{
				width = line.size();
			}
		}

		asciiLetter.letterWidth = width;
		//dictionary.emplace(letter.c_str(), asciiLetter);
		dictionary[*letter.c_str()] = asciiLetter;

		++iter;
	}

	return dictionary;
}