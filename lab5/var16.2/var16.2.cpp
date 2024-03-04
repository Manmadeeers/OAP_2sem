#include <iostream>
#include <string>//libraries
#include <fstream>
#define size 10
using namespace std;
union student {//union
	char FIO[50];
	char enter_date[50];
	char spec[50];
	int group;
	char faculty[50];
	float average;
}student;
//function prototypes
void enter_new();
void search();

void main()//main function
{
	char choise;
	do {
		//print variants
		cout << "1-Enter new information" << endl;
		cout << "2-Search" << endl;
		cout << "3-Clear console" << endl;
		cout << "4-Exit" << endl;
		cin >> choise;
		//check input
		while (!(choise >= '1' && choise <= '4')) {
			cout << "Invalid input!Try again: ";
			cin >> choise;
		}
		//convert char to int
		int choise_sw = choise - '0';
		switch (choise_sw) {
		case 1: enter_new(); break;
		case 2: search(); break;
		case 3: system("cls"); break;
		}

	} while (choise != '4');
}

void enter_new()//function for entering new information
{
	ofstream to_file("file.txt");//open file
	int curr_size = 0;
	//cycle to enter new information
	while (curr_size < size) {
		cout << "For student number " << curr_size + 1 << " :" << endl;
		//entering information
		cout << "Enter student's surename: ";
		cin.ignore();
		cin.getline(student.FIO, 50);
		to_file << student.FIO << ';';
		cout << "Enter student's name: ";
		cin.ignore();
		cin.getline(student.FIO, 50);
		to_file << student.FIO << ';';
		cout << "Enter student's patronimic: ";
		cin.ignore();
		cin.getline(student.FIO, 50);
		to_file << student.FIO << ';';
		cout << "Enter student's speciality: ";
		cin.ignore();
		cin.getline(student.spec, 50);
		to_file << student.spec << ';';
		cout << "Enter number of a group: ";
		cin >> student.group;
		to_file << student.group << ';';
		cout << "Enter the name of a faculty: ";
		cin.ignore();
		cin.getline(student.faculty, 50);
		to_file << student.faculty << ';';
		cout << "Enter student's average score: ";
		cin >> student.average;
		to_file << student.average << ';' << endl;
		curr_size++;//go to the next student
	}
	cout << "All the information is sucsessfully entered!" << endl;
	cout << "What's next?" << endl;

	to_file.close();//close file
}

void search()//fucntion to search
{
	ifstream from_file("file.txt");//open file to read
	float search_score;
	cout << "Enter average score to search: ";
	cin >> search_score;//getting the score to search
	string curr_string;
	bool check_var = false;
	//cycle to check all the lines of a file
	while (getline(from_file,curr_string)) {
		int curr_length = curr_string.length();//getting the length of a current string
		int amm_of_words = 0;
		//cycle to count words 
		for (int i = 0; i < curr_length; i++) {
			if (curr_string[i] == ';') {
				amm_of_words++;
			}
		}
		string* arr_of_words= new string[amm_of_words];//create an array of words
		int word_position = 0;
		//cycle to fill an array with words
		for (int i = 0; i < curr_length; i++) {
			if (curr_string[i] != ';') {
				arr_of_words[word_position] += curr_string[i];
			}
			else {
				word_position++;
			}
		}
		//get the average score from a file
		float curr_score = stof(arr_of_words[6]);
		if (curr_score == search_score) {//if such a student is found
			cout << "There is such a student!" << endl;
			check_var = true;
			cout << "Surename: " << arr_of_words[0] << endl;
			cout << "Name: " << arr_of_words[1] << endl;
			cout << "Patronimic: " << arr_of_words[2] << endl;
			cout << "Specialisation: " << arr_of_words[3] << endl;
			cout << "Group: " << arr_of_words[4] << endl;
			cout << "Faculty: " << arr_of_words[5] << endl;
		}
	}
	if (check_var == false) {//if such a stident is not found
		cout << "There are no students with such average score." << endl;
	}
	cout << "What's next?" << endl;

	from_file.close();//close file
}