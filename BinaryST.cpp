#include"BinaryST.h"





BinarySearchTree::~BinarySearchTree()
{
	DeleteBST(rootPtr);
}


// IsLeaf() --- Test if a node is a leaf
bool BinarySearchTree::IsLeaf(TreePtr treePtr)
{
	return ((treePtr->leftPtr == NULL) &&
		(treePtr->rightPtr == NULL));
}


// AddNode()
// Add (insert) new item into the BST, whose
// root node is pointed to by "rootPtr". If
// the data already exists, it is ignored.
// Sort by Alphabetical Title
void BinarySearchTree::AddNode(DATA_TYPE newData)
{
	TreePtr newPtr;
	newPtr = new BSTreeNode;
	newPtr->data = newData;
	newPtr->leftPtr = NULL;
	newPtr->rightPtr = NULL;

	// If the BST is empty, insert the new data in root
	if (rootPtr == NULL)
		rootPtr = newPtr;

	else // Look for the insertion location
	{
		TreePtr treePtr = rootPtr;
		TreePtr targetNodePtr = NULL;
		while (treePtr != NULL)
		{
			targetNodePtr = treePtr;
			if (newData == treePtr->data)
				// Found same data; ignore it.
				return;

			// will return 1 if newdata is alphabeticaly before treeptr->data->title
			else if (inOrderAlph(newData->title, treePtr->data->title)) 
				treePtr = treePtr->leftPtr;

			else 
				treePtr = treePtr->rightPtr;
		}
		
		if (inOrderAlph(newData->title, targetNodePtr->data->title))
			targetNodePtr->leftPtr = newPtr;
		else 
			targetNodePtr->rightPtr = newPtr;
	}
}

// DeleteBST()
// Delete an entire BST. All memory is released
// using a "PostOrder" traversal method.
void BinarySearchTree::DeleteBST(TreePtr& treePtr)
{
	if (treePtr != NULL)
	{
		DeleteBST(treePtr->leftPtr);
		DeleteBST(treePtr->rightPtr);
		delete treePtr;
		treePtr = NULL;
	}
}

void BinarySearchTree::SearchNode(DATA_TYPE searchKey)
{
	TreePtr srchPtr = NULL;
	srchPtr = SearchNodeInBST(rootPtr, searchKey);
	if (srchPtr != NULL)
	{
		cout << "\n Node: " << srchPtr->data << " found in the BST" << endl;
	}
	else
	{
		cout << "\n Node: " << searchKey << " not found" << endl;
	}
}


// SearchNodeInBST()
// Find a given node by "key" in BST. If successful, it
// returns the pointer that points to the node with "key";
// otherwise, it returns NULL. It uses preorder traversal.
BinarySearchTree::TreePtr
BinarySearchTree::SearchNodeInBST(TreePtr treePtr, DATA_TYPE key)
{
	if (treePtr != NULL) {
		if (key == treePtr->data)
			return treePtr;
		else if (key < treePtr->data)
			// Search for "key" in left subtree
			SearchNodeInBST(treePtr->leftPtr, key);
		else // (key > tree_ptr->data)
		// Search for "key" in right subtree
			SearchNodeInBST(treePtr->rightPtr, key);
	}
	else {
		return NULL;
	}
}






void BinarySearchTree::DeleteNode(TreePtr& treePtr, DATA_TYPE val)
{
	if (treePtr == NULL) {
		return;
	}
	else if (val == treePtr->data) {
		DeleteNodeItem(treePtr);
	}
	else if (val < treePtr->data) {
		DeleteNode(treePtr->leftPtr, val);
	}
	else {
		DeleteNode(treePtr->rightPtr, val);
	}
}


void BinarySearchTree::DeleteNodeItem(TreePtr& treePtr)
{
	TreePtr delPtr;
	if (IsLeaf(treePtr)) {
		delete treePtr;
		treePtr = NULL;
	}
	else if (treePtr->leftPtr == NULL) {
		delPtr = treePtr;
		treePtr = treePtr->rightPtr;
		delPtr->rightPtr = NULL;
		delete delPtr;
	}
	else if (treePtr->rightPtr == NULL) {
		delPtr = treePtr;
		treePtr = treePtr->leftPtr;
		delPtr->leftPtr = NULL;
		delete delPtr;
	}
	else {
		DATA_TYPE replacementItem;
		ProcessLeftMost(treePtr->rightPtr, replacementItem);
		treePtr->data = replacementItem;
	}
}


void BinarySearchTree::ProcessLeftMost(TreePtr& treePtr, DATA_TYPE& theItem)
{
	if (treePtr->leftPtr != NULL)
		ProcessLeftMost(treePtr->leftPtr, theItem);
	else
	{
		theItem = treePtr->data;
		TreePtr delPtr = treePtr;
		treePtr = treePtr->rightPtr;
		delPtr->rightPtr = NULL;
		delete delPtr;
	}
}





/// PRINT AND FIND FUNCTIONS ///



// PrintInOrder()
// Print BST using InOrder traversal
void BinarySearchTree::printShows()
{
	PrintBST_InOrder(rootPtr);
}

void BinarySearchTree::PrintBST_InOrder(
	TreePtr treePtr)
{
	if (treePtr != NULL)
	{
		// Print left BST subtree
		PrintBST_InOrder(treePtr->leftPtr);
		// Print Root node data
		cout << treePtr->data->title << endl;
		// Print right BST subtree
		PrintBST_InOrder(treePtr->rightPtr);
	}
}

//Public Fuction
void BinarySearchTree::printActors(string show) {
	cout << "Actors in " << show << ": " << endl;
	printActors(rootPtr, show);
}

//Private Function
void BinarySearchTree::printActors(TreePtr treePtr, string show) {
	if (treePtr->leftPtr != NULL)
		printActors(treePtr->leftPtr, show);

	if (stripStr(treePtr->data->title) == stripStr(show)) {
		for (int i = 0; i < size(treePtr->data->actors); i++) {
			cout << "   " << treePtr->data->actors[i] << endl;
		}
	}

	if (treePtr->rightPtr != NULL)
		printActors(treePtr->rightPtr, show);
}










// _______________________________________________________________
//
// THERE IS A PROBLEM WITH THESE TWO FUNCTIONS !!!
// Each node in the binary tree is a struct that contains a list of actors...
// this fuction is trying to iterate through those actors to see if a certain person is 
// in the show... if they are it will print the title of the show
// 
// The problem is that the stack overflows...
//

//Public Function
void BinarySearchTree::printShows(string actor) {
	cout << "Shows With " << actor << "in it: " << endl;
	printShows(rootPtr, actor);
}

//Private Function (Recursive)
void BinarySearchTree::printShows(TreePtr treePtr, string &actor) {
	
	for (int i = 0; i < treePtr->data->actors.size(); i++) {
		if (treePtr->data->actors[i] == actor)
			cout << "   " << treePtr->data->title << endl;
	}

	if (treePtr->leftPtr != NULL)
		printShows(treePtr->leftPtr, actor);
	
	if (treePtr->rightPtr != NULL)
		printShows(treePtr->rightPtr, actor);
}








//_________________________________________________________________
/*
//public
void BinarySearchTree::printShows(int startYear, int endYear) {
	cout << "Shows from " << startYear << " to " << endYear << ":" << endl;
	printShows(rootPtr, startYear, endYear);
}

void BinarySearchTree::printShows(TreePtr treePtr, int startYear, int endYear) {

	if (treePtr->leftPtr != NULL)
		printShows(treePtr->leftPtr, startYear, endYear);
	
	//split years apart from the data->year string
	string mYears = stripStr(treePtr->data->year);
	string sYear;
	sYear = mYears[0] + mYears[1] + mYears[2] + mYears[3];
	cout << "SYEAR: " << sYear << endl;
	string eYear;
	eYear = mYears[4] + mYears[5] + mYears[6] + mYears[7];
	cout << "EYEAR: " << eYear << endl;


	if (treePtr->rightPtr != NULL)
		printShows(treePtr->rightPtr, startYear, endYear);

}

*/