#include <iostream>//libraries
#include <string>
#include <fstream>
#define size 5
using namespace std;

union notebook {//union
	char FIO[50];
	long long bday_date;
	long long phone_number;
	char work_place[100];
	char position[100];

}card;

//function prototypes
void enter_new();
void search();


void main()//main function
{
	char choise;
	do {
		cout << "1-Enter new information" << endl;
		cout << "2-Search" << endl;
		cout << "3-Clear console" << endl;
		cout << "4-Exit" << endl;
		cin >> choise;
		//check if everything is entered the right way
		while (!(choise >= '1' && choise <= '4')) {
			cout << "Incorrect data!Try again: ";
			cin >> choise;
		}
		int choise_sw = choise - '0';//convert char to integer
		switch (choise_sw) {//switch-case
		case 1: enter_new(); break;
		case 2: search(); break;
		case 3: system("cls"); break;
		}
	} while (choise != '4');
}

void enter_new()//function for entering new information
{
	ofstream to_file("file.txt");//open file to write down
	cout << "Enter new information" << endl;
	int count_size = 0;
	//cycle for entering new information
	while (count_size < size) {
		cout << "For a person number " << count_size + 1 << " : " << endl;
		cout << "Enter surename: ";
		cin.ignore(cin.rdbuf()->in_avail());//clearing buffer
		cin.getline(card.FIO,50);
		to_file << card.FIO << ';';//writing information down
		cout << "Enter name: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(card.FIO, 50);
		to_file << card.FIO << ';';
		cout << "Enter patronimic: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(card.FIO, 50);
		to_file << card.FIO << ';';
		cout << "Enter the birthday date: ";
		cin >> card.bday_date;
		to_file << card.bday_date << ';';
		cout << "Enter the phone number: ";
		cin >> card.phone_number;
		to_file << card.phone_number << ';';
		cout << "Enter the workplace: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(card.work_place, 100);
		to_file << card.work_place << ';';
		cout << "Enter position: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(card.position, 100);
		to_file << card.position << ';' << endl;//go to the next string of a file
		count_size++;//go to the next card
	}

	to_file.close();//close file
}

void search()//function to search info
{
	ifstream from_file("file.txt");
	string search_string;//string to search
	cout << "Enter surename to search: ";
	cin.ignore();//clearing buffer
	getline(cin, search_string);
	string get_from;
	bool is_there = false;//creating a variable to check 
	while (getline(from_file,get_from)) {
		string get_surename;//string for current surename
		int curr_digit = 0;
		//cycle to get surename only
		while (get_from[curr_digit] != ';') {
			get_surename += get_from[curr_digit];
			curr_digit++;//go to the next digit
		}
		//check if the right surename is found
		if (get_surename == search_string) {
			cout << "There is such a card!" << endl;
			int curr_str_length = get_from.length();//getting length of current string from a file
			//getting amount of words
			int amm_of_words = 0;
			for (int i = 0; i < curr_str_length; i++) {
				if (get_from[i] == ';'){
					amm_of_words++;
				}
			}
			string* arr_of_words = new string[amm_of_words];//creating an array of strings for words
			//filling an array with words only
			int current_word = 0;
			for (int i = 0; i < curr_str_length; i++) {
				if (get_from[i] != ';') {
					arr_of_words[current_word] += get_from[i];
				}
				else {
					current_word++;
				}
			}
			//print infromation
			cout << "Surename: " << arr_of_words[0] << endl;
			cout << "Name: " << arr_of_words[1] << endl;
			cout << "Patronimic: " << arr_of_words[2] << endl;
			cout << "Birthday date: " << arr_of_words[3] << endl;
			cout << "Phone number: " << "+" << arr_of_words[4] << endl;
			cout << "Workplace: " << arr_of_words[5] << endl;
			cout << "Position: " << arr_of_words[6] << endl;
			is_there = true;
		}
	}
	if (is_there == false) {//if such a surename is not found
		cout << "There is no such a card." << endl;
	}
	cout << "What's next?" << endl;

	from_file.close();
}