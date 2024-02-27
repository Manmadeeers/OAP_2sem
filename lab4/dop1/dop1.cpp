#include <iostream>//libraries
#include <fstream>
#include <string>
using namespace std;
#define size 3//defining the size of an array of structures

struct Student {//structure prototype
	string surename;
	string name;
	string patronimic;
	int amm_of_exams;
	int first_grade;
	int sec_grade;
	int thir_grade;
	int fou_grade;
};
int curr_size = 0;

struct Student list_of_students[size];
//function prototypes
void enter_new();
void check_fives();
void mid_marks();

void main()//main function
{
	int choise;//variable for switch-case operators
	do {
		//printing the variants of usage
		cout << "1-Enter new information" << endl;
		cout << "2-To check a certain student's exm marks" << endl;
		cout << "3-To calculate the percentage of highgraders" << endl;
		cout << "4-To exit the program" << endl;
		cin >> choise;
		cin.ignore();//clearing the buffer
		//switch-case operators
		switch (choise) {
		case 1:enter_new(); break;	
		case 2:check_fives(); break;
		case 3:mid_marks(); break;
		}
	} while (choise != 4);
}

void enter_new()//function to enter the info
{
	ofstream to_file("file.txt");//opening the file to write down
	while (curr_size < size) {//writing info down while possible
		//getting all the info needed
		cout << "Student No. " << curr_size + 1 << " : " << endl;
		cout << "Surename: ";
		cin >> list_of_students[curr_size].surename;
		to_file << list_of_students[curr_size].surename << ' ';
		cin.ignore();
		cout << "Name: ";
		cin >> list_of_students[curr_size].name;
		cin.ignore();
		cout << "Patronimic: ";
		cin >> list_of_students[curr_size].patronimic;
		cin.ignore();
		cout << "The amount of exams: ";
		cin >> list_of_students[curr_size].amm_of_exams;
		cout << "First mark: ";
		cin >> list_of_students[curr_size].first_grade;
		to_file << list_of_students[curr_size].first_grade << ' ';
		cout << "Second mark: ";
		cin >> list_of_students[curr_size].sec_grade;
		to_file << list_of_students[curr_size].sec_grade << ' ';
		cout << "Third mark: ";
		cin >> list_of_students[curr_size].thir_grade;
		to_file << list_of_students[curr_size].thir_grade << ' ';
		cout << "Fourth mark: ";
		cin >> list_of_students[curr_size].fou_grade;
		to_file << list_of_students[curr_size].fou_grade << endl;
		curr_size++;
	}
	to_file.close();//closing the file
	cout << "All the data are entered!" << endl;
	cout << "What's next?" << endl;
}

void check_fives()//function to check if all the exams are passed with 4 or 5
{
	string search_student;//getting a string with a surename o a student to search for such a card
	cout << "Enter a surename of student to check: ";
	getline(cin, search_student);
	cin.ignore();
	bool is_there_a_student = false;//logic variable to define is there such a student or not
	for (int i = 0; i < size; i++) {//checking all the cards
		if (list_of_students[i].surename == search_student) {//if there such a card
			is_there_a_student = true;//changing the value of a logic variable
			//define is it a highgrader
			if (list_of_students[i].first_grade >= 4 && list_of_students[i].sec_grade >= 4 && list_of_students[i].thir_grade >= 4 && list_of_students[i].fou_grade >= 4) {
				cout << "Exams are passed with all the 4 and 5!" << endl;
			}
			else {//if not
				cout << "Not all the exams are passed with 4 and 5!" << endl;
			}
		}
	}
	//if there's no such a stident
	if (is_there_a_student == false) {
		cout << "There is no such a student!" << endl;
	}
	cout << "What's next?" << endl;
}
void mid_marks()//function to calculate the percentage of highgrdaders
{
	int high_graders = 0;
	ifstream from_file("file.txt");//open file to read
	string str_from_file;
	//untill it's possible to read string from a file
	while (getline(from_file, str_from_file)) {
		int curr_length = str_from_file.length();//getting the length of a current string
		int count_spaces = 0;
		for (int i = 0; i < curr_length; i++) {//calculating the ammount of spaces
			if (str_from_file[i] == ' ') {
				count_spaces++;
			}
		}
		int amm_of_words = count_spaces + 1;//calculating the ammount of words
		string* arr_of_words = new string[amm_of_words];//creating an array for words only
		int place_in_arr = 0;
		for (int i = 0; i < curr_length; i++) {//filling an array with words only
			if (str_from_file[i] != ' ') {
				arr_of_words += str_from_file[i];
			}
			else {
				place_in_arr++;
			}
		}
		int controll_var = 0;//creating a controll variable
		for (int i = 1; i < amm_of_words; i++) {//counting highgraders

			if (stoi(arr_of_words[i]) >= 4) {
				controll_var++;
			}
		}
		if (controll_var == 4) {//if the requirement is met
			high_graders++;
		}
		cin.ignore();

	}
	double percentage = (high_graders / size) * 100;//calculating the percentage of highgraders
	cout << "The percentage of highgraders is " << percentage << "%" << endl;
	cout << "What's next?" << endl;
	from_file.close();//closing the file
}
