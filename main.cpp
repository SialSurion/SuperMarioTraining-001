#include "Dictionary.h"
#include <iostream>
//#include <cstdio>
//#include <windows.h>
//#define MAX_INPUT_LENGTH 255

using namespace std;

int main()
{
	Dictionary dict;
	/*
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	wchar_t wstr[MAX_INPUT_LENGTH];
	char mb_str[MAX_INPUT_LENGTH * 3 + 1];

	unsigned long read;
	void* con = GetStdHandle(STD_INPUT_HANDLE);

	ReadConsole(con, wstr, MAX_INPUT_LENGTH, &read, NULL);*/

	//int size = WideCharToMultiByte(CP_UTF8, 0, wstr, read, mb_str, sizeof(mb_str), NULL, NULL);
	//mb_str[size] = 0;

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