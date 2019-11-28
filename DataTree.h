//Chiu Tze To     SID: 55726127     LID: LA2
#ifndef DataTree_h
#define DataTree_h
#include <iostream>
#include <string>
#include "DataNode.h"

using namespace std;
class DataTree
{
public:
	DataNode* root;
	DataNode* temp;
	int Total;

public:
	DataTree();
	~DataTree();
	bool IsEmpty();
	int height(DataNode* h);
	int max(int h1, int h2);
	DataNode* GetRoot();
	DataNode* SingleRotateWithLeft(DataNode* k2);
	DataNode* SingleRotateWithRight(DataNode* k1);
	DataNode* DoubleRotateWithLeft(DataNode* k);
	DataNode* DoubleRotateWithRight(DataNode* k);
	void InsertNode(string str1, string str2, string str3, string str4, string str5, string str6, string str7, string str8);
	DataNode* DeleteNode(DataNode*& Target, const int ID);
	/*DataNode* FindNode(DataNode* Target, const int ID);
	DataNode* FindMin(DataNode* Target);
	DataNode* FindMax(DataNode* Target);
	void preOrder(DataNode* Target);
	void inOrder(DataNode* Target);
	void postOrder(DataNode* Target);*/
};
#endif