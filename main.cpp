/* TvShowBinaryTree
 *
 * CS 121.Bolden.........Compiler version...........Tyler Gehring
 * 4/23/2024 .................Computer & CPU.............gehr6306@vandals.uidaho.edu
 *
 * Purpose of this program is to be able to read from a txt doc and create a binary tree of
 * data based on the information about movies and shows from the txt doc
 * My GitHub code https://github.com/tylergehring/ReadingTvShowData
 *---------------------------------------------------------------------
 */


#include"fileHandling.h"
#include"additionalFunct.h"


int main() {
	cout << "TvShowBinaryTree.CPP: READS from a txt doc to create a binary tree of movie show data..." << endl;
	cout << "PROGRAMED BY TYLER GEHRING, 4/23/24\n" << endl;


	string tfile = "data.txt";
	FileHandling file(tfile);
	file.getData();
	file.printInOrder();
	//cout << filterYear("Kung Fu : The Legend Continues(1993 - 1997)") << endl;
	
	file.printActors("Northern Exposure");
	file.printActors("seinfeld");
	
	file.printShows("Chris Potter");
	file.printShows("Tim Russ");



	file.printShows(1965, 1985);
	file.printShows(1990, 2000);

	return 0;
}