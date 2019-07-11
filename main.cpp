#include "Dictionary.h"
#include <iostream>

using namespace std;

int main()
{
	Dictionary dict;
	
	string userInput;
	cout << "Please provide text to be transformed to ASCII Art:" << endl;
	getline(cin, userInput);

	dict.printAsciiArt(userInput);

	//string test = "Test";
	//string superMario = "Super Mario";

	//dict.printAsciiArt(test);
	//dict.printAsciiArt(superMario);

	system("pause");

	return 0;
}