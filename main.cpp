#include"fileHandling.h"
#include"additionalFunct.h"


int main() {
	string tfile = "data.txt";
	FileHandling file(tfile);
	file.getData();
	file.printInOrder();
	//cout << filterYear("Kung Fu : The Legend Continues(1993 - 1997)") << endl;
	
	file.printActors("Northern Exposure:. ");
	file.printActors("seinfeld");
	
	file.printShows("Chris Potter");
	file.printShows("Tim Russ");


	file.printShows(1988, 2000);

	return 0;
}