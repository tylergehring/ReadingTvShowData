#include"additionalFunct.h"


string filterYear(string target) {
	char c;
	string year;
	bool openParen = false;

	for (auto& c : target) {
		// if we are reading between the "()" that means we are reading the year
		if (c == ')') {
			openParen = false;
		}
		if (openParen) {
			year += c; 
		}
		if (c == '(') {
			openParen = true;
		}
	}
	return year;
}




string filterTitle(string title) {
	char c;
	string t;
	bool stop = false;

	for (auto& c : title) {
		if (c == '(') {
			stop = true;
		}
		if (!stop) {
			t += c;
		}
	}

	return t;
}


int alphabeticalPrecedence(char c) {
	return ((int)c - 48);
}

//returns true if string target word comes before compare word alphabeticaly.
bool inOrderAlph(string targetWord, string compareWord) { 
	if (targetWord == compareWord) {
		return 1;
	}
	
	int i = -1;
	do {
		i++;
		if (alphabeticalPrecedence(targetWord[i]) < alphabeticalPrecedence(compareWord[i])) {
			return 1;
		}
		else if (alphabeticalPrecedence(targetWord[i]) > alphabeticalPrecedence(compareWord[i])) {
			return 0;
		}
	} while (alphabeticalPrecedence(targetWord[i]) == alphabeticalPrecedence(compareWord[i]));
}

string stripStr(string word) {
	string newWord;
	char c = ' ';
	for (auto& c : word){
		if (c != ' ' && c != ',' && c != ';' && c != '.' && c != ':' && c != '\'' && c != '-')
			newWord += tolower(c);
	}

	return newWord;
}


// calculates the int value of a string of numerical values
int strToInt(string str) {
	int size = str.size();

	int total = 0;

	for (int i = 0; i < size; i++) {
		total += ((int)str[i] - 48) * power(10, ((size - 1) - i));
	}
	return total;
}

// raises a number to a power
int power(int x, int power) {
	if (power == 0) {
		return 1;
	}
	else {
		int total = x;
		for (int i = 1; i < power; i++) {
			total = total * x;
		}

		return total;
	}
}