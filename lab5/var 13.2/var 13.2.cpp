#include <iostream>//libraries
#include <string>
#include <fstream>
#define size 5
using namespace std;

union state {//union
	char name[50];
	char capital[50];
	long long people;
	double square;
	char president[50];
}state;

//function prototype
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
		int choise_sw = choise - '0';//convert char to int
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
		//enter new information
		cout << "For state number " << curr_size + 1 << " : " << endl;//count the number of a state
		cout << "Enter the name of a state: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(state.name, 50);
		to_file << state.name << ';';
		cout << "Enter the state's capital: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(state.capital, 50);
		to_file << state.capital << ';';
		cout << "Enter the population: ";
		cin >> state.people;
		to_file << state.people << ';';
		cout << "Enter the states square: ";
		cin >> state.square;
		to_file << state.square << ';';
		cout << "Enter a surename of a president: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(state.president, 50);
		to_file << state.president << ';' << endl;//go to the next string in a file
		curr_size++;
	}
	cout << "All the information is sucsessfully entered!" << endl;
	cout << "What's next?" << endl;
	to_file.close();//close file
}

void search()//function for search
{
	ifstream from_file("file.txt");//open file to read
	string search_string;
	cout << "Enter the name of a state to search: ";
	cin.ignore();//clear the buffer
	getline(cin, search_string);//getting the string
	string curr_string;
	//cycle to check all the lines of a file
	bool check_var = false;
	while (getline(from_file,curr_string)) {
		string check_name;
		int curr_digit = 0;
		//cycle to get the name only
		while (curr_string[curr_digit] != ';') {
			check_name += curr_string[curr_digit];
			curr_digit++;
		}
		if (check_name == search_string) {//if such a state is found
			check_var = true;
			int amm_of_words = 0;
			int curr_length = curr_string.length();//getting the length of a current string
			for (int i = 0; i < curr_length; i++) {
				if (curr_string[i] == ';') {//calculating the ammount of words
					amm_of_words++;
				}
			}
			string* arr_of_words = new string[amm_of_words];//create an array of words
			int curr_word = 0;
			//filling an array with words only
			for (int i = 0; i < curr_length; i++) {
				if (curr_string[i] != ';') {
					arr_of_words[curr_word] += curr_string[i];
				}
				else {
					curr_word++;
				}
			}
			//print the required information
			cout << "There is such a state!" << endl;
			cout << "Name" << arr_of_words[0] << endl;
			cout << "Capital: " << arr_of_words[1] << endl;
			cout << "Population: " << arr_of_words[2] << endl;
			cout << "Square: " << arr_of_words[3] << endl;
			cout << "Surename of a president: " << arr_of_words[4] << endl;
		}
	}
	if (check_var = false) {//if the required state is not found
		cout << "There is no such a state." << endl;
	}
	cout << "What's next?" << endl;

	from_file.close();//close file
}