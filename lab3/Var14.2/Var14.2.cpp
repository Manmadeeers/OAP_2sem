#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//function prototypes
void write_down(string);
void read_from();

void main()//main function
{
	setlocale(LC_ALL, "Russian");
	string enter_string;
	//entering string
	cout << "Enter the string: ";
	getline(cin, enter_string);

	//usage of functions
	write_down(enter_string);
	read_from();
}

void write_down(string str)//function to write information down
{
	//opening file to write info down
	ofstream to_file("file.txt");
	//check if it's possible to open the file
	if (to_file.is_open()) {
		to_file << str;
		cout << "All the information is sucsessfully written down!" << endl;
	}
	else {
		cout << "Failed to open the file!" << endl;
		exit(1);
	}

}

void read_from()//function to read info from a file
{
	//opening the file to read
	ifstream from_file("file.txt");
	//check if it's possible to open the file
	if (from_file.is_open()) {
		//read a string from a file
		string str_from_file;
		getline(from_file, str_from_file);
		int k;
		//getting the length of the string devision
		cout << "How many symbols should the first string contain?: ";
		cin >> k;
		int from_length = str_from_file.length();
		//check if k is nor more or less then a length of a whole string
		while (k > from_length || k <1) {
			cout << "Enter a NORMAL number!";
			cin >> k;
		}
		string part1;
		//deviding a string in two parts
		for (int i = 0; i < k; i++) {
			part1 += str_from_file[i];
		}
		cout << "First part of a string: " << part1 << endl;
		string part2;
		for (int i = k; i < from_length; i++) {
			part2 += str_from_file[i];
		}
		cout << "Second part of a string: " << part2 << endl;

	}
	else {
		cout << "Failed to open the file!" << endl;
		exit(1);
	}
}