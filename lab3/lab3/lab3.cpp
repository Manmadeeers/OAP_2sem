#include <iostream>//including libraries
#include <fstream>
#include <string>
//standard namespace
using namespace std;

void main()//main function
{
	setlocale(LC_ALL, "rus");//console localisation
	//opening files for executiong and writing down information

	ifstream first_file("FILE1.txt");
	ofstream second_file("FILE2.txt");

	//check if it's possible to open a file
	if (first_file.is_open() && second_file.is_open()) {
		string file_line;
		string first_word,first_line;
		getline(first_file, first_line);
		int count_letters_in_first = 0;
		//cycle to get the first word from the first line
		while (first_line[count_letters_in_first] != ' ') {
			first_word += first_line[count_letters_in_first];
			count_letters_in_first++;
		}
		//print the first word in a console
		cout << "The first word in FILE1: " << first_word << endl;
		//cycle to read all the lines of a first file
		second_file << first_line << endl;
		//a variable to count all the letters in FILE2
		int count_letters = 0;
		while (getline(first_file, file_line)) {
			string check_string;//string var for the first word of each line
			int count_var = 0;//variable to help get the forst ord of each line
			//getting the first word of each line
			while (file_line[count_var] != ' ') {
				check_string += file_line[count_var];
				count_var++;
			}
			//if the first words of the strings are simillar - write down the string to the second file
			if (check_string == first_word) {
				second_file << file_line << endl;
				int curr_str_length = file_line.length();//var to count the length of the current string
				//cycle to count all the letters in FILE2
				for (int i = 0; i < curr_str_length; i++) {
					if (file_line[i] != ' ') {
						count_letters++;
					}
				}
			}

		}
		cout << "The whole ammount of letters in the FILE2 is: " << count_letters << endl;
		cout << "Program is sucsessfully finished!" << endl;
	}
	//if omthing went wrong while opening the files
	else {
		cout << "Can not open the files!";
		exit(1);
	}

	//close all the files
	first_file.close();
	second_file.close();

}