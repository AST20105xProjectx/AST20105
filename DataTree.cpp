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
	//cout << " < " << newNode->Code << " " << newNode->PhoneNumber << endl;
	cout << "Insert Success!\n";
	delete newNode;
	Total++;
}

/*DataNode* DataTree::DeleteNode(DataNode*& Target, const int ID)
{

}

/*DataNode* deleteNode(DataNode*& Target, const int ID);
DataNode* findNode(DataNode* Target, const int ID);
DataNode* findMin(DataNode* Target);
DataNode* findMax(DataNode* Target);*/