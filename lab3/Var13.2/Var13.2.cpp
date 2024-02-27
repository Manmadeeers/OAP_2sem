#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//function prototypes
void write_down(string);
void read_from();

void main()
{
	setlocale(LC_ALL, "Russian");
	string str_to_file;
	cout << "Введите строку из символов и скобок разного вида: ";
	getline(cin, str_to_file);
	//clearing buffer
	cin.ignore(cin.rdbuf()->in_avail());
	write_down(str_to_file);
	read_from();
}

void write_down(string str)
{
	//opening file to write smth down
	ofstream to_file("File.txt");
	//check if it's possible to open the file
	if (to_file.is_open()) {
		to_file << str;
		cout << "Information is sucsessfully written down!" << endl;
	}
	else {
		cout << "Failed to open the file!" << endl;
		exit(1);
	}
	//closing the file after writing down
	to_file.close();
}


void read_from()
{
	//open file to read from
	ifstream from_file("File.txt");
	//heck if it's possible to open the file
	if (from_file.is_open()) {
		string str_from_file;//string from  file
		getline(from_file, str_from_file);
		//calculating length of a string
		int str_length = str_from_file.length();
		int count_scob = 0;
		//counting digits
		for (int i = 0; i < str_length; i++) {
			if (str_from_file[i] == ')' || str_from_file[i] == '(' || str_from_file[i] == '[' || str_from_file[i] == ']' || str_from_file[i] == '{' || str_from_file[i] == '}') {
				count_scob++;
			}
		}
		cout << "Количество скобок разного вида равно: " << count_scob << endl;

	}
	else {
		cout << "Failed to open the file!" << endl;
		exit(1);
	}
	

	//close the file
	from_file.close();
}