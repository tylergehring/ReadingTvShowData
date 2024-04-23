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
	void printShows();
	void printActors(string show);
	void printShows(string actor);
	void printShows(int startYear, int endYear);

	
};



