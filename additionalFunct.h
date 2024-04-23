#pragma once
using namespace std;
#include<iostream>



string filterYear(string target); //returns the year out of the title line by reading inbetween the "()"
string filterTitle(string title); // returns just the title by reading everything up until '('


int alphabeticalPrecedence(char c);
bool inOrderAlph(string targetWord, string compareWord);

string stripStr(string word); //strips a string of all spaces and extra characters and returns the lowercase string
int strToInt(string str);


int power(int x, int power);

