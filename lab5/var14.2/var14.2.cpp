#include <iostream>//libraries
#include <string>
#include <fstream>
#define size 3
using namespace std;
enum rooms {//enum
	Lux=1,single,duple,triple,apartments
}rooms;
union client {//union
	char FIO[50];
	char pass_num[50];
	char date_in[10];
	char date_out[10];
}client;
//function prototype
void enter_new();
void search();


void main()//main function
{
	char choise;
	do {
		//print variants
		cout << "1-Enter new information" << endl;
		cout << "2-Search by surename" << endl;
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
		//switch
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
		//entering new information
		cout << "For client number " << curr_size + 1 << " :" << endl;
		//writing down to the file
		cout << "Enter client's surename: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(client.FIO, 50);
		to_file << client.FIO << ';';
		cout << "Enter client's name: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(client.FIO, 50);
		to_file << client.FIO << ';';
		cout << "Enter client's patronimic: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(client.FIO, 50);
		to_file << client.FIO << ';';
		cout << "Enter client's passport series and number: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(client.pass_num, 50);
		to_file << client.pass_num << ';';
		cout << "Enter the check-in day: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(client.date_in, 10);
		to_file << client.date_in << ';';
		cout << "Enter the check-out date: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(client.date_out, 10);
		to_file << client.date_out << ';';
		int room_type;//variable to use enum
		cout << "Choose the room type: " << endl;
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
		//choosing a room type
		switch (room_type) {
		case 1:to_file << "Luxury" << ';' << endl;
		case 2:to_file << "Single" << ';' << endl;
		case 3:to_file << "Double" << ';' << endl;
		case 4:to_file << "Triple" << ';' << endl;
		case 5:to_file << "Apartments" << ';' << endl;
		}
		curr_size++;//go to the next client
	}
	cout << "All the information is sucsessfully entered!" << endl;
	cout << "What's next?" << endl;

	to_file.close();//close file
}

void search()//function to search by surename
{
	ifstream from_file("file.txt");//open file to read
	string search_str;
	cout << "Enter a surename to search: ";
	cin.ignore();
	getline(cin, search_str);//getting a string to search
	string curr_string;//string from a file
	bool check_var = false;
	while (getline(from_file, curr_string)) {//cycle to get every string
		string curr_surename;
		int curr_digit = 0;
		//cycle to get a surename of a client only
		while (curr_string[curr_digit] != ';') {
			curr_surename += curr_string[curr_digit];
			curr_digit++;
		}
		if (curr_surename == search_str) {//if there is such a surename
			check_var = true;
			cout << "There is such a client!" << endl;
			int amm_of_words = 0;
			int curr_length = curr_string.length();//getting the length of a current string
			//cycle to count words
			for (int i = 0; i < curr_length; i++) {
				if (curr_string[i] == ';') {
					amm_of_words++;
				}
			}
			string* arr_of_words = new string[amm_of_words];//creating an array of strings
			//cycle to fill an array with information
			int word_position = 0;
			for (int i = 0; i < curr_length; i++) {
				if (curr_string[i] != ';') {
					arr_of_words[word_position] += curr_string[i];
				}
				else {
					word_position++;
				}
			}
			//print required information
			cout << "Surename: " << arr_of_words[0] << endl;
			cout << "Name: " << arr_of_words[1] << endl;
			cout << "Patronimic: " << arr_of_words[2] << endl;
			cout << "Passport data: " << arr_of_words[3] << endl;
			cout << "Check-in date: " << arr_of_words[4] << endl;
			cout << "Check-out date: " << arr_of_words[5] << endl;
			cout << "Room type: " << arr_of_words[6] << endl;
		}
	}
	if (check_var == false) {//if entered surename is not found
		cout << "There is no such a client." << endl;
	}
	cout << "What's next?" << endl;

	from_file.close();//close file
}