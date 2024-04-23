// Additional functions that are used throughout the program

#pragma once
using namespace std;
#include<iostream>



string filterYear(string target); //returns the year out of the title line by reading inbetween the "()"
string filterTitle(string title); // returns just the title by reading everything up until '('


int alphabeticalPrecedence(char c); // returns an int based on ascII characters a = a smaller number than z
bool inOrderAlph(string targetWord, string compareWord); // if targetword comes before compareWord it will return 1

string stripStr(string word); //strips a string of all spaces and extra characters and returns the lowercase string
int strToInt(string str);  //takes a string of numbers and converts them into its base 10 value


int power(int x, int power); //simple exponent function

