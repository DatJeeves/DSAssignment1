// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "reader.cpp"


using namespace std;

int main(int argc, char** argv) {
	//basic vars
	string path = " ";
	char choice = ' ';
	bool run = true;
	bool a = false;
	//constructor
	Reader* r = new Reader();
	//Checks for argument num
	if (!argv[1]) {
		cout << "Error, file not included." << endl;
		return 1;
	}
	else if (r->getFirst() == false) {
		cout << "Enter the path to your file to read (with the .txt attatched): ";
		cin >> path;
	}
	//statement for the choice of continuing
	while (run) {
		//reading file and calculating
		path = argv[1];
		r->read(path);
		a = r->calculations(path);
		//output messages for error checking
		if (a == false) {
			cout << "Calculations not preformed correctly" << endl;
		}
		else if (a == true) {
			cout << "Calculations performed correctly" << endl;
			//outputs data to file
			r->output();
		}
		else {
			cout << "Calculation did not return a valid value" << endl;
			break;
		}
		//checks for correct response
		while (true) {
			cout << "Do you want to contine? type 'y' for YES and 'n' for NO: ";
			cin >> choice;
			if (choice == 'n' || choice == 'N') {
				run = false;
				r->~Reader();
				break;
			}
			else if (choice == 'y' || choice == 'Y') {
				//resets values so new and clean operation
				r->reset();
				run = true;
				r->setFirst(false);
				break;
			}
			else {
				cout << "You did not enter a valid responce." << endl;
			}
		}

	}
	return 0;
}


	




/*
1.) Read class
	Needs to assign vars - create an object/string each time
2.) Math vars for st. dev ect.
3.) Probibility
4.) Writes strings following curve
5.) Exports a .out file
6.) Loop
*/