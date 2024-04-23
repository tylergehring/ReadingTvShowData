#include"fileHandling.h"
#include"additionalFunct.h"


int main() {
	string tfile = "data.txt";
	FileHandling file(tfile);
	file.getData();
	//file.printInOrder();
	//cout << filterYear("Kung Fu : The Legend Continues(1993 - 1997)") << endl;
	
	//file.printActors("Northern Exposure:. ");
	//file.printActors("Walker tExas Ranger");
	
	//file.printShows("Chris Potter");
	file.printShows("Chuck Norris");


	//file.printShows(2020, 2024);

	return 0;
}