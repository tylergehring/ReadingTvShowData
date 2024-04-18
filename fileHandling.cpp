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
	
	char c;
	string temp;
	
	/* my char get line function
	while (file >> noskipws >> c) {
		if (c != ',' && c != ';' && c != '.' && c !='\n') {
			c = tolower(c);
			title += c;
		}
		else if (c == '\n') {
			break;
		}
	}
	*/

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
	
	cout << year << " " << title << endl;
	file.close();
}

