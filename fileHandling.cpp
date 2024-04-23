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

		LinkedList<string> actor;
		getline(file, temp); //gets first actor
		while (temp.size() > 1) {
			actor.push(temp);
			getline(file, temp);
		}
		
		moviePtr movieStruct;
		movieStruct = new Movie;

		movieStruct->title = title;
		movieStruct->link = link;
		movieStruct->movieType = movieType;
		movieStruct->year = year;

		for (int i = 0; i < actor.getSize(); i++) {
			movieStruct->actors.push(actor.getVal(i));
		}

		movieTree.AddNode(movieStruct);
	}


	file.close();
}



void FileHandling::printShows() {
	movieTree.printShows();
	cout << endl;
}

void FileHandling::printActors(string show) {
	movieTree.printActors(show);
	cout << endl;
}

void FileHandling::printShows(string actor){
	movieTree.printShows(actor);
	cout << endl;
}


void FileHandling::printShows(int startYear, int endYear) {
	movieTree.printShows(startYear, endYear);
	cout << endl;
}


