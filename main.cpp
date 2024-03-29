//Chiu Tze To     SID: 55726127     LID: LA2
#include <iostream>
#include <fstream>
#include <string>
#include "DataNode.h"
#include "DataTree.h"
#include "Menu.h"
#include "ctime"

using namespace std;

// Reading User file data
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

// Seperate the long string into different attribute and store it in the Data Tree
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
	cout << "There are total of " << Tree->Total << " data inserted!\n\n";
}

int main()
{
	Meun m;
	long long Phone;
	string str1, str2;
	DataNode* T;
	cout << "Welcome to our program! \n";
	cout << "======================= \n";

	string fileString = "";
	DataTree *Tree = new DataTree;
	fileString = readFile();
	SeperateFile(fileString,Tree);

	int choice = 0;
	// Exit the Program by inputting -1
	while (choice != -1)
	{
		m.MainMeun();
		cin >> choice;
		// Insertion of dataset
		if (choice == 1)
		{
			//Deletion of old data

			string fileString = "";
			DataTree* Tree = new DataTree;
			fileString = readFile();
			SeperateFile(fileString, Tree);
		}
		// Deletion of record(s)
		else if (choice == 2)
		{
			m.Deletion();
			cin >> choice;
			if (choice == 1)
			{
				cout << "Please type in the Phone Number in numbers ONLY (eg. 12345678900: ";
				cin >> Phone;
			}
			else if (choice == 2)
			{
				
			}
			else
				cout << "Invalid input! \n";
		}
		// Searching for record(s)
		else if (choice == 3)
		{
			m.Search();
			cin >> choice;
			m.Search2(choice);
			// Searching Phone Number /+ 1 attribute
			if (choice == 1 || (choice >= 5 && choice <= 7))
			{
				cin >> Phone;
				if (choice == 1)
				{
					T = Tree->root;
					Tree->PhoneSearch(T, Phone);
				}
				if (choice == 5)
				{
					cout << "Please type in the Skills: ";
					cin >> str1;
					T = Tree->root;
					Tree->DoubleSearchPhone(T, Phone, str1, choice);
				}
				else if (choice == 6)
				{
					cout << "Please type in the Job Title: ";
					cin >> str1;
					T = Tree->root;
					Tree->DoubleSearchPhone(T, Phone, str1, choice);
				}
				else if (choice == 7)
				{
					cout << "Please type in the Country: ";
					cin >> str1;
					T = Tree->root;
					Tree->DoubleSearchPhone(T, Phone, str1, choice);
				}
			}
			// Searching Skills /+ 1 attribute
			else if (choice == 2 || choice == 8 || choice == 9)
			{
				cin >> str1;
				if (choice == 2)
				{
					T = Tree->root;
					Tree->SkillsSearch(T, str1);
				}
				else if (choice == 8)
				{
					cout << "Please type in the Job Title: ";
					cin >> str2;
					T = Tree->root;
					Tree->DoubleSearchXPhone(T, str1, str2, choice);
				}
				else if (choice == 9)
				{
					cout << "Please type in the Country: ";
					cin >> str2;
					T = Tree->root;
					Tree->DoubleSearchXPhone(T, str1, str2, choice);
				}
			}
			// Searching Job Title /+ Country
			else if (choice == 3 || choice == 10)
			{
				cin >> str1;
				if (choice == 3)
				{
					T = Tree->root;
					Tree->JobSearch(T, str1);
				}
				else if (choice == 10)
				{
					cout << "Please type in the Country: ";
					cin >> str2;
					T = Tree->root;
					Tree->DoubleSearchXPhone(T, str1, str2, choice);
				}
			}
			//Searching Country
			else if (choice == 4)
			{
				cin >> str1;
				T = Tree->root;
				Tree->CountrySearch(T, str1);
			}
			else
				cout << "Invalid Input! \n";
		}
		else
		{
			if (choice != -1)
				cout << "Invalid Input! \n\n";
		}
	}
	system("pause");
	return 0;
}