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