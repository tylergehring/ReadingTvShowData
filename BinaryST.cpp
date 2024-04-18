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
void BinarySearchTree::AddNode(DATA_TYPE newData)
{
	TreePtr newPtr;
	newPtr = new BSTreeNode;
	// Add new data in the new node�s data field
	newPtr->data = newData;
	newPtr->leftPtr = NULL;
	newPtr->rightPtr = NULL;
	// If the BST is empty, insert the new data in root
	if (rootPtr == NULL)
	{
		rootPtr = newPtr;
	}
	else // Look for the insertion location
	{
		TreePtr treePtr = rootPtr;
		TreePtr targetNodePtr;
		while (treePtr != NULL)
		{
			targetNodePtr = treePtr;
			if (newData == treePtr->data)
				// Found same data; ignore it.
				return;
			else if (newData < treePtr->data)
				// Search left subtree for insertion location
				treePtr = treePtr->leftPtr;
			else // newData > treePtr->data
			// Search right subtree for insertion location
				treePtr = treePtr->rightPtr;
		}
		// "targetNodePtr" is the pointer to the
		// parent of the new node. Decide where
		// it will be inserted.
		if (newData < targetNodePtr->data)
			targetNodePtr->leftPtr = newPtr;
		else // insert it as its right child
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


// PrintTree()
// Print a BST tree uses InOrder traversal by default.
void BinarySearchTree::PrintTree()
{
	PrintBST_InOrder(rootPtr);
}


// PrintInOrder()
// Print BST using InOrder traversal
void BinarySearchTree::PrintInOrder()
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
		cout << treePtr->data << endl;
		// Print right BST subtree
		PrintBST_InOrder(treePtr->rightPtr);
	}
}

// PrintPreOrder()
// Print BST using PreOrder traversal
void BinarySearchTree::PrintPreOrder()
{
	PrintBST_PreOrder(rootPtr);
}
void BinarySearchTree::PrintBST_PreOrder(
	TreePtr treePtr)
{
	if (treePtr != NULL)
	{
		// Print node data
		cout << treePtr->data << endl;
		// Print left subtree
		PrintBST_PreOrder(treePtr->leftPtr);
		// Print right subtree
		PrintBST_PreOrder(treePtr->rightPtr);
	}
}

// PrintPostOrder()
// Print BST using PostOrder traversal
void BinarySearchTree::PrintPostOrder()
{
	PrintBST_PostOrder(rootPtr);
}
void BinarySearchTree::PrintBST_PostOrder(
	TreePtr treePtr)
{
	if (treePtr != NULL)
	{
		// Print left BST subtree
		PrintBST_PostOrder(treePtr->leftPtr);
		// Print right BST subtree
		PrintBST_PostOrder(treePtr->rightPtr);
		// Print node data
		cout << treePtr->data << endl;
	}
}

// Print BST using InOrder traversal
void BinarySearchTree::PrintBackwardInOrder()
{
	PrintBST_BackwardInOrder(rootPtr, 0);
}
void BinarySearchTree::PrintBST_BackwardInOrder(
	TreePtr treePtr, int depth)
{
	const int INDENT = 4;
	if (treePtr != NULL) {
		// Print right BST subtree
		PrintBST_BackwardInOrder(treePtr->rightPtr, depth + 1);
		// Print data in root node
		//cout << setw(INDENT*depth) << " ";
		for (int i = 0; i < INDENT * depth; i++) cout << " ";
		cout << treePtr->data << endl;
		// Print left BST subtree
		PrintBST_BackwardInOrder(treePtr->leftPtr, depth + 1);
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