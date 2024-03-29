//Chiu Tze To     SID: 55726127     LID: LA2
#include <iostream>
#include <string>
#include "Menu.h"

using namespace std;

Meun::Meun()
{
}

Meun::~Meun()
{
}

void Meun::MainMeun()
{
	cout << "What do you want to do? \n";
	cout << "Choice 1 : Insertion of dataset \n";
	cout << "Choice 2 : Deletion of record(s) \n";
	cout << "Choice 3 : Searching for record(s) \n";
	cout << "Choice -1 : Exit the program \n";
	cout << "---------------------------------- \n";
	cout << "Please type in your choice number(eg: 1): ";
}

void Meun::Deletion()
{
	cout << "You want to delete the specific data by PhoneNumber or Country?";
	cout << "Choice 1 : By PhoneNumber \n";
	cout << "Choice 2 : By Country \n";
}

void Meun::Search()
{
	cout << " Search by single attribute: \n";
	cout << "Choice 1 : By PhoneNumber \n";
	cout << "Choice 2 : By Skills \n";
	cout << "Choice 3 : By Job Title \n";
	cout << "Choice 4 : By Country \n";
	cout << "----------------------------";
	cout << "Search by double attributes: \n";
	cout << "Choice 5 : By PhoneNumber + Skills \n";
	cout << "Choice 6 : By PhoneNumber + Job Title \n";
	cout << "Choice 7 : By PhoneNumber + Country \n";
	cout << "Choice 8 : By Skills + Job Title \n";
	cout << "Choice 9 : By Skills + Country \n";
	cout << "Choice 10 : By Job Title + Country \n\n";
	cout << "PLease type in the corresponding choice that you want to search: ";
}

void Meun::Search2(int choice)
{
	switch (choice)
	{
	case 1:
		cout << "Please type in the Phone Number in numbers ONLY (eg. 12345678900: ";
		break;
	case 2:
		cout << "Please type in the Skills: ";
		break;
	case 3:
		cout << "Please type in the Job Title: ";
		break;
	case 4:
		cout << "Please type in the Country: ";
		break;
	case 5:
	case 6:
	case 7:
		cout << "Please type in the Phone Number first: ";
		break;
	case 8:
	case 9:
		cout << "Please type in the Skills first: ";
		break;
	case 10:
		cout << "Please type in the Job Title first: ";
		break;
	default:
		cout << "Invalid input! \n";
		break;
	}
}