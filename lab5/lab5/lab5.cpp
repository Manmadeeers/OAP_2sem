#include <iostream>//libraries
#include <string>
#define size 5
using namespace std;
struct Personal {//structure prototype
	string surename;
	string name;
	string patronimic;
	string adress;
	long long phone;
};

struct Personal arr_of_people[size];//creating an array

//function prototypes
void enter_new();
void search();


void main()//main function
{
	char choise;
	do {
		//print variants of usage
		cout << "1-Enter new information" << endl;
		cout << "2-Search" << endl;
		cout << "3-Clear console" << endl;
		cout << "4-Exit" << endl;
		cin >> choise;
		//check if everything is entered correctly
		while (!(choise >= '1' && choise <= '4')) {
			cout << "Incorrect format!Try again: ";
			cin >> choise;
		}
		//converting char to int
		int choise_sw = choise - '0';
		//variants of usage
		switch (choise_sw) {
		case 1:enter_new(); break;
		case 2: search(); break;
		case 3:system("cls"); break;
		}
	} while (choise != '4');
}

void enter_new()//function for entering new information
{
	cout << "Entering new information:" << endl;
	int count_var = 0;//counting variable
	long long phone_number;
	while (count_var < size) {//cycle to enter info
		cout << "For a person number " << count_var + 1 << " : " << endl;
		cout << "Enter surename: ";
		cin >> arr_of_people[count_var].surename;
		cout << "Enter name: ";
		cin >> arr_of_people[count_var].name;
		cout << "Enter patronimic: ";
		cin >> arr_of_people[count_var].patronimic;
		string curr_adress;
		cout << "Enter the adress: ";
		cin.ignore();
		getline(cin, curr_adress);//using a string to prevent 
		arr_of_people[count_var].adress=curr_adress;
		cout << "Enter phone number: ";
		cin >> phone_number;
		arr_of_people[count_var].phone = phone_number;//entering the phone number using bit fields

		count_var++;
	}
	cout << "All the information is sucsessfully entered!" << endl;
	cout << "What's next?" << endl;
}

void search()//fucntion for searching by name
{
	string search_name;//getting the name to search
	cout << "Enter the name to search: ";
	cin.ignore();//clearing buffer5
	getline(cin, search_name);
	//cycle to search through all the cards
	bool is_there = false;
	for (int i = 0; i < size; i++) {
		string curr_name = arr_of_people[i].name;//getting the name of a person from each card
		if (curr_name == search_name) {
			is_there = true;//changing the value of a logic variable 
			//print the data needed
			cout << "There is such a note!" << endl;
			cout << "Surename: " << arr_of_people[i].surename << endl;
			cout << "Name: " << arr_of_people[i].name << endl;
			cout << "Patronimic: " << arr_of_people[i].patronimic << endl;
			cout << "Adress: " << arr_of_people[i].adress << endl;
			cout << "Phone number: " << arr_of_people[i].phone << endl;
		}
	}
	if (is_there == false) {//if such name is not found
		cout << "There are no notes with this name." << endl;
	}
	cout << "What's next?" << endl;
}