#include <iostream>//libraries
#include <string>
#include <fstream>
#define size 5
using namespace std;
enum types {
	lux=1,single,duble,triple,apartments
}types;
struct Client {//structure 
	string pass_num;
	unsigned  day_in : 4;
	unsigned int month_in : 4;
	unsigned int day_out : 4;
	unsigned int month_out : 4;
	string type;

};
struct Client arr_of_structs[size];//create an array of structures
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
		case 1:enter_new(); break;
		case 2:search(); break;
		case 3:system("cls"); break;
		}
	} while (choise != '4');//exit requirements
}

void enter_new()//function to enter new infromation
{
	int curr_size = 0;
	//cycle for entering new information
	while (curr_size < size) {
		//entering info
		cout << "For client number " << curr_size + 1 << " :" << endl;
		cout << "Enter passport series and number: ";
		cin.ignore();
		getline(cin, arr_of_structs[curr_size].pass_num);
		int day;//buffer variable
		cout << "Enter check-in day number: ";
		cin >> day;
		//check input
		while (day > 31) {
			cout << "Invalid input!Try again: ";
			cin >> day;
		}
		arr_of_structs[curr_size].day_in = day;//getting the check-in day
		int month;
		cout << "Enter check-in month number: ";
		cin >> month;
		//check input
		while (month > 12) {
			cout << "Invalid input!Try again: ";
			cin >> month;
		}
		arr_of_structs[curr_size].month_in = month;
		int d_out;
		cout << "Enter the check-out day number: ";
		cin >> d_out;
		//check_input
		while (d_out > 31) {
			cout << "Invalid input!Try again: ";
			cin >> d_out;
		}
		arr_of_structs[curr_size].day_out = d_out;
		int m_out;
		cout << "Enter the check-out month number: ";
		cin >> m_out;
		//check input
		while (m_out > 12) {
			cout << "Invalid input!Try again: ";
			cin >> m_out;
		}
		arr_of_structs[curr_size].month_out = m_out;
		//getting the room type using enum
		int room_type;
		cout << "Choose the type of a room:" << endl;
		cout << "1-Luxury room" << endl;
		cout << "2-Single room" << endl;
		cout << "3-Double room" << endl;
		cout << "4-Triple room" << endl;
		cout << "5-Apartments" << endl;
		cin >> room_type;
		//check input
		while (!(room_type >= 1 && room_type <= 5)) {
			cout << "Invalid input!Try again: ";
			cin >> room_type;
		}
		switch (room_type) {//getting the room type
		case 1:arr_of_structs[curr_size].type = "Luxury room";
		case 2:arr_of_structs[curr_size].type = "Single room";
		case 3:arr_of_structs[curr_size].type = "Double room";
		case 4:arr_of_structs[curr_size].type = "Triple room";
		case 5:arr_of_structs[curr_size].type = "Apartments";
		}
		curr_size++;
	}
	cout << "All the information is sucsessfully entered!" << endl;
	cout << "What's next?" << endl;
}

void search()//fuction to search information
{
	string search_date;
	cout << "Enter the date to search(day and month): ";
	cin.ignore();//clear buffer
	getline(cin, search_date);//get the string to search
	//get the day
	string curr_day;
	for (int i = 0; i < 2; i++) {
		curr_day += search_date[i];
	}
	//get the month
	string curr_month;
	for (int i = 2; i < 5; i++) {
		curr_month += search_date[i];
	}
	//transfering from string to int
	unsigned int day = stoi(curr_day);
	unsigned int month = stoi(curr_month);
	//check all the clients
	bool check_var = false;
	for (int i = 0; i < size; i++) {//if the requirement is met
		if (day == arr_of_structs[i].day_in && month == arr_of_structs[i].month_in) {
			check_var = true;
			//print the required information
			cout << "There is such a client!" << endl;
			cout << "Passport data: " << arr_of_structs[i].pass_num << endl;
			cout << "Check-out date: " << arr_of_structs[i].day_out << " : " << arr_of_structs[i].month_out << endl;
			cout << "Room type: " << arr_of_structs[i].type << endl;
		}
	}
	if (check_var == false) {//if the requirement is not met
		cout << "There are no clients checked in this day." << endl;
	}
	cout << "What's next?" << endl;
}