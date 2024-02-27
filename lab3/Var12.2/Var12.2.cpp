#include <iostream>//including libraries
#include <fstream>
#include <string>
//standard namespace
using namespace std;

//functions' prototypes
void write_down(string);
void read_from_file();

void main()//main function
{
	setlocale(LC_ALL, "Russian");
	string string_to_file;
	//getting the string
	cout << "Введите строку из слов и цифр: ";
	getline(cin, string_to_file);
	//clear the buffer to avoid errors
	cin.ignore(cin.rdbuf()->in_avail());
	//using the user functions
	write_down(string_to_file);
	read_from_file();
}

void write_down(string str_to_file)//function to write info down to the file
{
	//creating file to write down info
	ofstream string_to_file("File.txt");
	//check if it's possible to open the file
	if (string_to_file.is_open()) {
		string_to_file << str_to_file;
	}
	else {
		cout << "Failed to open the file." << endl;
		exit(1);
	}

	//closing the file after writing down the information
	string_to_file.close();
	cout << "Information is sucsessfully written down!" << endl;
}

void read_from_file()//function to read info from the file
{
	//opening the file to read info
	ifstream from_file("File.txt");
	string read_string;
	//getting the string from file
	getline(from_file, read_string);
	//calculating the length of a given string
	int str_length = read_string.length();
	//checking numbers in a string
	cout << "Нечётные числа строки: ";
	for (int i = 0; i < str_length; i++) {
		int check_numbers;
		//checking if it's a number
		if (read_string[i] >= '0' && read_string[i] <= '9') {
			check_numbers = read_string[i] - '0';
			//checking if it's odd or even
			if (check_numbers % 2 != 0) {
				cout << check_numbers << ' ';
			}
		}
	}


	//closing the file
	from_file.close();
}