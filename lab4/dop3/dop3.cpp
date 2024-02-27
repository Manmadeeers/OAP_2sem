#include <iostream>//libraries
#include <fstream>
#include <string>
#define size 4//defining the size of an array
using namespace std;

struct RESORT {//structure prototype
	string name;
	string place;
	string profile;
	int ammount;
};
struct RESORT list_of_resorts[size];//creating an array 
//function prototypes
void enter_new();
void group_profile();
void search();

void main()//main function
{
	char choise;//entering what to do with a program
	do {//print the usage variants
		cout << "1-Enter new information" << endl;
		cout << "2-Show the sorted version" << endl;
		cout << "3-Search" << endl;
		cout << "4-Clean console" << endl;
		cout << "5-Exit" << endl;
		cin >> choise;
		while (!(choise >= '1' && choise <= '5')) {//check if everething is entered correctly
			cout << "Incorrect format!Try again: ";
			cin >> choise;
		}

		int choise_sw = choise-'0';//convert char to int
		switch (choise_sw) {//switch case operator
		case 1: enter_new(); break;
		case 2: group_profile(); break;
		case 3: search(); break;
		case 4: system("cls"); break;
		}
	} while (choise!='5');//exit condition
}

void enter_new()//function for entering new information
{
	cout << "Entering new information" << endl;
	int count_size = 0;//creating count variable
	ofstream to_file("file.txt");//open file to write down
	while (count_size < size) {//cycle to enter new infromation
		//entering all the nesesery information
		cout << "For card number " << count_size+1 << " : " << endl;
		cout << "Enter the name of a resort: ";
		cin >> list_of_resorts[count_size].name;
		to_file << list_of_resorts[count_size].name << ' ';//writing down to file
		cout << "Enter the location: ";
		cin >> list_of_resorts[count_size].place;
		to_file << list_of_resorts[count_size].place << ' ';
		cout << "Enter the resort's profile: ";
		cin >> list_of_resorts[count_size].profile;
		to_file << list_of_resorts[count_size].profile << ' ';
		cout << "Enter the ammount of free places: ";
		cin >> list_of_resorts[count_size].ammount;
		to_file << list_of_resorts[count_size].ammount << endl;
		count_size++;//go to the next place in an array
	}
	cout << "All the information is sucsessfully entered!" << endl;
	cout << "What's next?" << endl;
	to_file.close();//close the file
}

void group_profile()//function that groups structures by profile
{
	//check all the resorts
	string* profiles = new string[size];//creating an array to store unique profiles
	int count_unique = 0;
	for (int i = 0; i < size; i++) {//cycle to check all the structures
		bool control_var = false;//creating a logic var to check if there any duplicates
		for (int j = 0; j < size; j++) {

			if (list_of_resorts[i].profile == profiles[j]) {//if there is a duplicate
				control_var = true;
				break;//exit the cycle
			}
		}
		if (control_var == false) {//if this is unique
			profiles[count_unique] = list_of_resorts[i].profile;//send to the array
			count_unique++;
		}
	}
	//print all the resorts with the same profile
	for (int i = 0; i < count_unique; i++) {//cycles to print resorts with certain profiles
		cout << "Resorts with " << profiles[i] << " profile: " << endl;
		for (int j = 0; j < size; j++) {
			//check if the profiles are simmilar
			if (list_of_resorts[j].profile == profiles[i]) {//print information about a resort with a certain profile
				cout << "Resort name: " << list_of_resorts[j].name << endl;
				cout << "Resort location: " << list_of_resorts[j].place << endl;
				cout << "Ammount of free palces: " << list_of_resorts[j].ammount << endl;
			}
		}
	}
	cout << "What's next?" << endl;
}

void search()//function to search information
{
	string name_search;//entering the name of a resort to search
	cout << "Enter the name of a resort: ";
	getline(cin, name_search);
	cin.ignore();
	ifstream from_file("file.txt");//open file to read information
	string str_from_file;
	//get every single line from a file
	bool check_file = false;//create a var to check if there such a resort
	while (getline(from_file, str_from_file)) {
		int count_spaces = 0;
		//count spaces to be able to calculate the ammount of words
		for (int i = 0; i < str_from_file.length(); i++) {
			if (str_from_file[i] == ' ') {
				count_spaces++;
			}
		}
		//calculating ammount of words
		int amm_of_words = count_spaces++;
		string* arr_of_words = new string[amm_of_words];//create an array for words
		int pos_in_arr = 0;
		//filling an array with words
		for (int i = 0; i < str_from_file.length(); i++) {
			if (str_from_file[i] != ' ') {
				arr_of_words[pos_in_arr] += str_from_file[i];
			}
			else {
				pos_in_arr++;
			}
		}
		string curr_name = arr_of_words[0];//getting the current name of a resort
		string curr_location = arr_of_words[1];//getting the current resort location
		string curr_profile = arr_of_words[2];//getting the current resort profile
		if (curr_name == name_search) {//if entered name is found
			//print all the information needed
			cout << "There is such a resort!" << endl;
			cout << "Resort location: " << curr_location << endl;
			cout << "Resort profile: " << curr_profile << endl;
			check_file = true;//change the value of a logic variable
		}
	}
	if (check_file == false) {//if entered name is not found
		cout << "Unfortunately, there is no such a resort." << endl;
	}
	cout << "What's next?" << endl;
	from_file.close();//close file
}