#include"fileHandling.h"
#include"additionalFunct.h"


FileHandling::FileHandling(string file) {
	try {
		fstream temp;
		temp.open(file);
		if (temp.eof()) {
			cout << "FILE IS EMPTY; ERROR: FILEHANDLING::FILEHANDLING()" << endl;
			exit(0);
		}
		temp.close();
	}
	
	catch (...) {
		cout << "CANNOT OPEN TXT FILE; ERROR: FILEHANDLING::FILEHANDING()" << endl;
		exit(0);
	}

	targetFile = file;
}


void FileHandling::getData() {
	fstream file;
	file.open(targetFile);
	string temp;
	
	while (!file.eof()) {

		getline(file, temp);
		string year = filterYear(temp);
		string title = filterTitle(temp);

		getline(file, temp);
		string movieType = temp;

		getline(file, temp);
		string link = temp;

		getline(file, temp); //gets first actor
		vector<string> actors;
		while (temp.size() > 1) {
			actors.push_back(temp);
			getline(file, temp);
		}
		


		moviePtr movieStruct;
		movieStruct = new Movie;

		movieStruct->title = title;
		movieStruct->link = link;
		movieStruct->movieType = movieType;
		movieStruct->year = year;
		movieStruct->actors = actors;

		movieTree.AddNode(movieStruct);
	}


	file.close();
}

void FileHandling::printInOrder(){
	movieTree.printShows();
}



void FileHandling::printShows() {

}

void FileHandling::printActors(string show) {
	movieTree.printActors(show);
}

void FileHandling::printShows(string actor){
	movieTree.printShows(actor);
}

/*
void FileHandling::printShows(int startYear, int endYear) {
	movieTree.printShows(startYear, endYear);

}
*/

