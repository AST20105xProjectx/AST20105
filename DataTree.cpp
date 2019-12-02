//Chiu Tze To     SID: 55726127     LID: LA2
#include <iostream>
#include <string>
#include "DataNode.h"
#include "DataTree.h"

using namespace std;

DataTree::DataTree()
{
	root = temp = NULL ;
	Total = 0;
}

DataTree::~DataTree()
{

}

bool DataTree::IsEmpty()
{
	return root == NULL ? true : false;
}

int DataTree::height(DataNode* h)
{
	if (h == NULL)
		return -1;
	else
		return h->height;
}

int DataTree::max(int h1, int h2)
{
	if (h1 > h2)
		return h1;
	else
		return h2;
}

DataNode* DataTree::GetRoot()
{
	return root;
}

DataNode* DataTree::SingleRotateWithLeft(DataNode* k2)
{
	DataNode* k1;
	k1 = k2->Left;
	k2->Left = k1->Right;
	k1->Right = k2;
	k2->height = max(height(k2->Left), height(k2->Right)) + 1;
	k1->height = max(height(k1->Left), k2->height) + 1;
	return k1;
}

DataNode* DataTree::SingleRotateWithRight(DataNode* k1)
{
	DataNode* k2;
	k2 = k1->Right;
	k1->Right = k2->Left;
	k2->Left = k1;
	k1->height = max(height(k1->Left), height(k1->Right)) + 1;
	k2->height = max(height(k2->Right), k1->height) + 1;
	return k2;
}

DataNode* DataTree::DoubleRotateWithLeft(DataNode* k)
{
	k->Left = SingleRotateWithRight(k->Left);
	return SingleRotateWithLeft(k);
}

DataNode* DataTree::DoubleRotateWithRight(DataNode* k)
{
	k->Right = SingleRotateWithLeft(k->Right);
	return SingleRotateWithRight(k);
}

void DataTree::InsertNode(string str1,string str2, string str3, string str4, string str5, string str6, string str7, string str8)
{
	DataNode* newNode = new DataNode(str1, str2, str3, str4, str5, str6, str7, str8);
	//cout << newNode->Code << " " << newNode->PhoneNumber << endl;
	cout << "Insert Success!\n";
	delete newNode;
	Total++;
}

/*DataNode* DataTree::DeleteNode(DataNode*& Target, const int ID)
{

}*/

DataNode* DataTree::PhoneFindNode(DataNode* n,long long PhoneNum)
{
	if (n == NULL)
		return NULL;
	if (PhoneNum < n->Code)
		return PhoneFindNode(n->Left, PhoneNum);
	else if (PhoneNum > n->Code)
		return PhoneFindNode(n->Right, PhoneNum);
	else
		return n;
}

void DataTree::PhoneSearch(DataNode* Target,long long PhoneNum)
{
	if (Target != NULL)
	{
		if (Target->Code == PhoneNum)
		{
			cout << Target->ID << "\t" << Target->JobTitle << "\t" << Target->EmailAddress << "\t" << Target->LastName << "\t"
				 << Target->FirstName << "\t" << Target->PhoneNumber << "\t" << Target->Skills << "\t" << Target->Country << "\n";
		}
		PhoneSearch(Target->Left,PhoneNum);
		PhoneSearch(Target->Right,PhoneNum);
	}
}

void DataTree::SkillsSearch(DataNode* Target, string skills)
{
	if (Target != NULL)
	{
		if (Target->Skills == skills)
		{
			cout << Target->ID << "\t" << Target->JobTitle << "\t" << Target->EmailAddress << "\t" << Target->LastName << "\t"
				<< Target->FirstName << "\t" << Target->PhoneNumber << "\t" << Target->Skills << "\t" << Target->Country << "\n";
		}
		SkillsSearch(Target->Left, skills);
		SkillsSearch(Target->Right, skills);
	}
}

void DataTree::JobSearch(DataNode* Target, string Job)
{
	if (Target != NULL)
	{
		if (Target->JobTitle == Job)
		{
			cout << Target->ID << "\t" << Target->JobTitle << "\t" << Target->EmailAddress << "\t" << Target->LastName << "\t"
				<< Target->FirstName << "\t" << Target->PhoneNumber << "\t" << Target->Skills << "\t" << Target->Country << "\n";
		}
		JobSearch(Target->Left, Job);
		JobSearch(Target->Right, Job);
	}
}

void DataTree::CountrySearch(DataNode* Target, string country)
{
	if (Target != NULL)
	{
		if (Target->Country == country)
		{
			cout << Target->ID << "\t" << Target->JobTitle << "\t" << Target->EmailAddress << "\t" << Target->LastName << "\t"
				<< Target->FirstName << "\t" << Target->PhoneNumber << "\t" << Target->Skills << "\t" << Target->Country << "\n";
		}
		CountrySearch(Target->Left, country);
		CountrySearch(Target->Right, country);
	}
}

void DataTree::DoubleSearchPhone(DataNode* Target, long long PhoneNum, string str, int choice)
{
	int control = 0;
	if (Target != NULL)
	{
		switch(choice)
		{
		case 5:
			if (Target->Code == PhoneNum && Target->Skills == str)
			{
				cout << Target->ID << "\t" << Target->JobTitle << "\t" << Target->EmailAddress << "\t" << Target->LastName << "\t"
					<< Target->FirstName << "\t" << Target->PhoneNumber << "\t" << Target->Skills << "\t" << Target->Country << "\n";
			}
			break;
		case 6:
			if (Target->Code == PhoneNum && Target->JobTitle == str)
			{
				cout << Target->ID << "\t" << Target->JobTitle << "\t" << Target->EmailAddress << "\t" << Target->LastName << "\t"
					<< Target->FirstName << "\t" << Target->PhoneNumber << "\t" << Target->Skills << "\t" << Target->Country << "\n";
			}
			break;
		case 7:
			if (Target->Code == PhoneNum && Target->Country == str)
			{
				cout << Target->ID << "\t" << Target->JobTitle << "\t" << Target->EmailAddress << "\t" << Target->LastName << "\t"
					<< Target->FirstName << "\t" << Target->PhoneNumber << "\t" << Target->Skills << "\t" << Target->Country << "\n";
			}
			break;
		default:
			cout << "You choose the invalid choice!\n";
			control = 1;
		}
		if (control == 0)
		{
			DoubleSearchPhone(Target->Left, PhoneNum, str, choice);
			DoubleSearchPhone(Target->Right, PhoneNum, str, choice);
		}
	}
}

void DataTree::DoubleSearchXPhone(DataNode* Target, string str1, string str2, int choice)
{
	int control = 0;
	if (Target != NULL)
	{
		switch (choice)
		{
		case 8:
			if (Target->Skills == str1 && Target->JobTitle == str2)
			{
				cout << Target->ID << "\t" << Target->JobTitle << "\t" << Target->EmailAddress << "\t" << Target->LastName << "\t"
					<< Target->FirstName << "\t" << Target->PhoneNumber << "\t" << Target->Skills << "\t" << Target->Country << "\n";
			}
			break;
		case 9:
			if (Target->Skills == str1 && Target->Country == str2)
			{
				cout << Target->ID << "\t" << Target->JobTitle << "\t" << Target->EmailAddress << "\t" << Target->LastName << "\t"
					<< Target->FirstName << "\t" << Target->PhoneNumber << "\t" << Target->Skills << "\t" << Target->Country << "\n";
			}
			break;
		case 10:
			if (Target->JobTitle == str1 && Target->Country == str2)
			{
				cout << Target->ID << "\t" << Target->JobTitle << "\t" << Target->EmailAddress << "\t" << Target->LastName << "\t"
					<< Target->FirstName << "\t" << Target->PhoneNumber << "\t" << Target->Skills << "\t" << Target->Country << "\n";
			}
			break;
		default:
			cout << "You choose the invalid choice!\n";
			control = 1;
		}
		if (control == 0)
		{
			DoubleSearchXPhone(Target->Left, str1, str2, choice);
			DoubleSearchXPhone(Target->Right, str1, str2, choice);
		}
	}
}