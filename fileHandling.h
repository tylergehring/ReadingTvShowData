#pragma once


//Purpose: Sort through text file and return pointers to sorted data structures

#include<string> //used for the getline function
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
	void getData(); // read the data from the txt doc and move it into a binary tree
	void printShows(); // print all shows out of the txt document
	void printActors(string show); // print the actors of a given show
	void printShows(string actor); // print the shows a given actor has been apart of
	void printShows(int startYear, int endYear); //print any shows that aired durring the given time period

	
};



