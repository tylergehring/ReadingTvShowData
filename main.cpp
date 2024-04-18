#include"fileHandling.h"
#include"additionalFunct.h"


int main() {
	string tfile = "simpleData.txt";
	FileHandling file(tfile);
	file.getData();
	//cout << filterYear("Kung Fu : The Legend Continues(1993 - 1997)") << endl;
	
	return 0;
}