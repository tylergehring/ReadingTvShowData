#pragma once


//Purpose: Sort through text file and return pointers to sorted data structures

#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include"BinaryST.h"

using namespace std;
//#include"BinaryST.h"
//#include"LinkedList.h"
//#include"charArr.h"

class FileHandling {
private:
	
	

	string targetFile;
	BinarySearchTree movieTree;

public:
	FileHandling(string file);
	void getData();
	void printInOrder();
	
	//BSTPtr getTitlesBST();
	//BSTPtr getActorsBST(); //return
	//BSTPtr getTitle(int year, int year); //return shows between a time period

	/*
	• Display all shows in the tree (only the titles!).
	• Display all actors of a given show in the tree: Perry Mason, The
		Office, The Prisoner, and two others of your choice.
	• Display all shows of a given actor: Raymond Burr, Bill Mumy,
		Bob Newhart, and two others of your choice.
	• Display all shows released between 1965 and 1985 and one other
		decade range of your choice
	
	*/
};



