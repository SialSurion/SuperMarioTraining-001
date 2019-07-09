#include "Dictionary.h"

using namespace std;

int main()
{
	Dictionary dict;
	auto lettersDict = dict.readCharToAsciiArtDictionary();

	/*for (auto itr = lettersDict.begin(); itr != lettersDict.end(); ++itr) {
		cout << itr->first
			<< '\t' << itr->second.lines[2] << '\n';
	}*/

	return 0;
}