#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define size 5
enum faculties {//enum 
	FIT=1,PIM,HTIT,LHF,LID,IEF
}facults;

struct Students {//structure prototype
	string surename;
	string name;
	string patronimic;
	string enter_date;
	string adress;
	long long phone_number;
	string facult;
};

struct Students arr_of_structs[size];//creating an array of structures

//function prototypes
void enter_new();
void search();

void main()//main function
{
	char choise;//choise var
	do {
		//print variants
		cout << "1-Enter new information" << endl;
		cout << "2-Search" << endl;
		cout << "3-Clear console" << endl;
		cout << "4-Exit" << endl;
		cin >> choise;
		//check if everething is entered the right way
		while (!(choise >= '1' && choise <= '4')) {
			cout << "Incorrect input! Try again: ";
			cin >> choise;
		}
		int choise_sw = choise - '0';//transfering char to int
		switch (choise_sw) {//variants
		case 1: enter_new(); break;
		case 2: search(); break;
		case 3: system("cls"); break;
		}
	} while (choise != '4');
}

void enter_new()//function for entering new information
{
	int curr_size = 0;//variable to check the ammount if structures
	while (curr_size < size) {//cycle to enter new information
		cout << "Student number " << curr_size + 1 << " : " << endl;
		cout << "Enter surename: ";
		cin.ignore();//clear buffer
		//entering information
		getline(cin, arr_of_structs[curr_size].surename);
		cout << "Enter name: ";
		cin.ignore();
		getline(cin, arr_of_structs[curr_size].name);
		cout << "Enter patronimic: ";
		cin.ignore();
		getline(cin, arr_of_structs[curr_size].patronimic);
		cout << "Enter the enter date(in DD.MM.YYYY format): ";
		cin.ignore();
		getline(cin, arr_of_structs[curr_size].enter_date);
		cout << "Enter the adress: ";
		cin.ignore();
		getline(cin, arr_of_structs[curr_size].adress);
		cout << "Enter the phone number: ";
		cin >> arr_of_structs[curr_size].phone_number;
		cout << "Enter the facultie:" << endl;
		//give faculties as a list
		int chosen_facult;
		cout << "1-FIT" << endl;
		cout << "2-PIM" << endl;
		cout << "3-HTIT" << endl;
		cout << "4-LHF" << endl;
		cout << "5-LID" << endl;
		cout << "6-IEF" << endl;
		cin >> chosen_facult;
		//use switch to use enum to choose a facultie
		switch (chosen_facult) {
		case 1: arr_of_structs[curr_size].facult = "FIT"; break;
		case 2: arr_of_structs[curr_size].facult = "PIM"; break;
		case 3: arr_of_structs[curr_size].facult = "HTIT"; break;
		case 4: arr_of_structs[curr_size].facult = "LHF"; break;
		case 5: arr_of_structs[curr_size].facult = "LID"; break;
		case 6: arr_of_structs[curr_size].facult = "IEF"; break;
		default:cout << "Invalid input" << endl;
		}
		curr_size++;//go to the next card
		system("cls");//clear the console 
	}
	cout << "All the information is sucsessfully entered!" << endl;
	cout << "What's next?" << endl;
}

void search()//function sor searching
{
	string search_string;//get the string to search by a surename
	cout << "Enter the surename to search: ";
	cin.ignore();//clear the buffer
	getline(cin, search_string);//getting the string
	//cycle to look through the entire array of structures
	bool check_var = false;//creating check-variable
	for (int i = 0; i < size; i++) {
		if (arr_of_structs[i].surename == search_string) {//if the requirement is met
			check_var = true;
			//print info
			cout << "there is such a student!" << endl;
			cout << "Surename: " << arr_of_structs[i].surename << endl;
			cout << "Name: " << arr_of_structs[i].name << endl;
			cout << "Patronimic: " << arr_of_structs[i].patronimic << endl;
			cout << "Univercity enter date: " << arr_of_structs[i].enter_date << endl;
			cout << "Adress: " << arr_of_structs[i].adress << endl;
			cout << "Phone number: " << arr_of_structs[i].phone_number << endl;
			cout << "Facultie: " << arr_of_structs[i].facult << endl;
		}
	}
	if (check_var == false) {//if the requirement is not met
		cout << "There is no such a student." << endl;
	}
	cout << "What's next?" << endl;
}