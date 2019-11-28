//Chiu Tze To     SID: 55726127     LID: LA2
#include <iostream>
#include <fstream>
#include <string>
#include "DataNode.h"
#include "DataTree.h"

using namespace std;

string readFile()
{
	string tempString = "";
	string filename;

	cout << "Input file name: ";
	cin >> filename;
	ifstream inputFile(filename);

	// Prompt user again if wrong filename received
	while (!inputFile.good())
	{
		cout << "Wrong file name, input again please: ";
		cin >> filename;
		inputFile.open(filename);
	}

	// Append all lines from the file into a long string
	while ((!inputFile.eof()))
	{
		string str;
		getline(inputFile, str);
		tempString += str;
	}
	inputFile.close();
	return tempString;
}

void SeperateFile(string fileString, DataTree* Tree)
{
	char* Ustr;
	char* Unstr;
	int Control = 0;
	string str1, str2, str3, str4, str5, str6, str7, str8;

		char* word = new char[fileString.size() + 1];
		fileString.copy(word, fileString.size() + 1);
		word[fileString.size()] = '\0';
		Ustr = strtok_s(word, "	", &Unstr);
	while (Ustr != NULL)
	{
		switch (Control % 8)
		{
		case 0:
			str1 = Ustr;
			break;
		case 1:
			str2 = Ustr;
			break;
		case 2:
			str3 = Ustr;
			break;
		case 3:
			str4 = Ustr;
			break;
		case 4:
			str5 = Ustr;
		case 5:
			str6 = Ustr;
			break;
		case 6:
			str7 = Ustr;
			break;
		case 7:
			str8 = Ustr;
			Tree->InsertNode(str1, str2, str3, str4, str5, str6, str7, str8);
			break;
		}
		Ustr = strtok_s(NULL, "	", &Unstr);
		Control++;
	}
	cout << "There are total of " << Tree->Total << " data inserted!\n";
}

int main()
{
	bool valid = true;
	string fileString = "";
	DataTree *Tree = new DataTree;
	fileString = readFile();
	SeperateFile(fileString,Tree);
	system("pause");
	return 0;
}