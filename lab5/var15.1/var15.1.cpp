#include <iostream>//libraries
#include <string>
#include <fstream>
#define size 5
using namespace std;
struct Exam {//structure
	string surename;
	string exam_name;
	unsigned int date : 10;
};
struct Exam arr_of_structs[size];//create an array of structures
//functuon prototypes
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
		//cinvert char to int
		int choise_sw = choise - '0';
		switch (choise_sw) {//switch
		case 1: enter_new(); break;
		case 2: search(); break;
		case 3: system("cls"); break;
		}

	} while (choise != '4');
}

void enter_new()//function for entering new infromation
{
	int curr_size = 0;
	//cycle to enter new info
	while (curr_size < size) {
		cout << "For exam number " << curr_size + 1 << " :" << endl;
		//enteing info
		cout << "Enter teachers surename: ";
		cin.ignore();//clear buffer
		getline(cin, arr_of_structs[curr_size].surename);
		cout << "Enter the exam discipline: ";
		cin.ignore();
		getline(cin, arr_of_structs[curr_size].exam_name);
		int temp_date;//use temporary variable to use bit fields
		cout << "Enter the exam date(day and month only): ";
		cin >> temp_date;
		arr_of_structs[curr_size].date = temp_date;
		curr_size++;//go to the next exam
	}
	cout << "All the information is sucsessfuly entered!" << endl;
	cout << "What's next?" << endl;
}

void search()//function to search
{
	unsigned int search_date;//getting the date to search
	cout << "Enter the date to search: ";
	cin >> search_date;
	bool check_var = false;
	//cycle to look through all the elements of an array
	for (int i = 0; i < size; i++) {
		//if there is such an exam
		if (search_date == arr_of_structs[i].date) {
			check_var = true;
			cout << "There is such an exam!" << endl;
			cout << "Teachers surename: " << arr_of_structs[i].surename << endl;
			cout << "Exam name: " << arr_of_structs[i].exam_name << endl;
		}
	}
	if (check_var == false) {//if there are no such exams
		cout << "There is no such an exam at this time" << endl;
	}
	cout << "What's next?" << endl;
}