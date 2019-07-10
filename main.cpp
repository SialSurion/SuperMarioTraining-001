#include "Dictionary.h"

using namespace std;

int main()
{
	Dictionary dict;

	string test = "Test";
	string superMario = "Super Mario";

	dict.printAsciiArt(test);
	dict.printAsciiArt(superMario);

	return 0;
}