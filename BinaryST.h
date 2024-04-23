#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include"additionalFunct.h"

struct Movie {
	vector<string> actors;
	string title;
	string link;
	string movieType;
	string year;
};
typedef Movie* moviePtr;



#ifndef _BSTREE_H_
#define _BSTREE_H_
typedef moviePtr DATA_TYPE; // Type of node’s data

class BinarySearchTree
{
private:
	typedef struct BSTreeNode
	{
		DATA_TYPE data;
		BSTreeNode* leftPtr{ NULL };
		BSTreeNode* rightPtr{ NULL };
	} *TreePtr;
	TreePtr rootPtr; // root of the BST
	void InitBSTree()
	{
		rootPtr = NULL;
	}
	void DeleteBST(TreePtr& treePtr);
	void DeleteNode(TreePtr& treePtr, DATA_TYPE val);
	void DeleteNodeItem(TreePtr& treePtr);
	void ProcessLeftMost(TreePtr& treePtr, DATA_TYPE& theItem);
	bool IsLeaf(TreePtr treePtr);
	TreePtr SearchNodeInBST(TreePtr treePtr, DATA_TYPE searchKey);
	void PrintBST_InOrder(TreePtr treePtr);
	void printActors(TreePtr treePtr, string show);
	void printShows(TreePtr treePtr, string &actor);
	//void printShows(TreePtr treePtr, int startYear, int endYear);

public:
	BinarySearchTree() { InitBSTree(); }
	~BinarySearchTree();
	bool IsEmpty()
	{
		return (rootPtr == NULL);
	}
	void AddNode(DATA_TYPE newData);
	void SearchNode(DATA_TYPE searchKey);
	//void DeleteNode(DATA_TYPE val);
	void printShows();
	void printActors(string show);
	void printShows(string actor);
	//void printShows(int startYear, int endYear);
	//TreePtr searchShow(string show);
	//TreePtr searchActor(string actor); 
	
};
#endif

