#include <iostream>//libraries
#include <fstream>
#include <string>

using namespace std;

//function prototypes
void to_file(string);
void from_file();


void main()//main function
{
	string str_to_file;
	//entering a string
	cout << "Enter a string: ";
	getline(cin, str_to_file);
	//clear a buffer
	cin.ignore(cin.rdbuf()->in_avail());
	to_file(str_to_file);
	from_file();
}

void to_file(string str)
{
	//open file to write down
	ofstream to_file("file.txt");
	//check if it's possible to open the file
	if (to_file.is_open()) {
		to_file << str;
	}
	else {
		cout << "Failed to open the file!" << endl;
		exit(1);
	}
	cout << "All the information is sucsessfully written down!" << endl;

	//close file
	to_file.close();
}

void from_file()
{
	//open file to read
	ifstream from_file("file.txt");
	string from_str;
	//getting a string form file
	getline(from_file, from_str);
	int count_spaces = 0;
	int length = from_str.length();
	//count spaces in a string
	for (int i = 0; i < length; i++) {
		if (from_str[i] == ' ') {
			count_spaces++;
		}
	}
	//get an ammount of words in a string
	int amm_of_words = count_spaces + 1;
	//create an array for words
	string* arr = new string[amm_of_words];
	int j = 0;
	//filling an array with words only
	for (int i = 0; i < length; i++) {
		if (from_str[i] != ' ') {
			arr[j] += from_str[i];
		}
		else {
			j++;
		}
	}
	cout << "Words with letter x in them: ";
	//cycle to identify words with the letter x in them
	for (int i = 0; i < amm_of_words; i++) {
		int curr_length = arr[i].length();
		for (int k = 0; k < curr_length; k++) {
			if (arr[i][k] == 'x' || arr[i][k] == 'X') {
				cout << arr[i] << ' ';
				break;
			}
		}
	}
	//close file
	from_file.close();
}