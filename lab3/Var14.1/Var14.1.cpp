#include <iostream>//including libraries
#include <fstream>
#include <string>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	//open files to read and write down
	ifstream from_file("FILE1.txt");
	ofstream to_file("FILE2.txt");
	//check if it's possible to open the files
	if (from_file.is_open() && to_file.is_open()) {
		string file_line;
		while (getline(from_file, file_line)) {
			int curr_length = file_line.length();
			//count spaces in a string to calculate the ammount of words
			int count_spaces = 0;
			for (int i = 0; i < curr_length; i++) {
				//counting spaces
				if (file_line[i] == ' ') {
					count_spaces++;
				}
			}
			//calculating the ammount of words in a string
			int amm_of_words = count_spaces + 1;
			string* arr_of_words = new string[amm_of_words];
			int j = 0;
			//filling an array with words from a string
			for (int i = 0; i < curr_length; i++) {
				if (file_line[i] != ' ') {
					arr_of_words[j] += file_line[i];
				}
				else {
					i++;
					j++;
				}
			}
			//check if there a simillar word
			int k = amm_of_words - 1;
			//cycke to check all the words in a string
			for (int i = 1; i < amm_of_words; i++) {
				if (i == k) {
					i++;
				}

				if (arr_of_words[k] == arr_of_words[i]) {
					to_file << file_line;
					break;
				}
				k--;
			}

		}
	}
	else {
		cout << "Failed to open the files!" << endl;
		exit(1);
	}
	cout << "All the information is sucsessfully written down!" << endl;
	//open file2 to read
	ifstream from_sec("FILE2.txt");
	if (from_sec.is_open()) {
		string str_for_a;
		//check all the strings from file2
		int number_of_max;
		while (getline(from_sec, str_for_a)) {
			int count_spaces_sec = 0;
			int length_sec = str_for_a.length();
			//count sapces to be able to count words
			for (int i = 0; i < length_sec; i++) {
				if (str_for_a[i] == ' ') {
					count_spaces_sec++;
				}
			}
			int amm_of_words_sec = count_spaces_sec + 1;
			//create an array for words of a string
			string* arr_of_sec = new string[amm_of_words_sec];
			//cycle to fill an array with words from string
			int place_in_arr = 0;
			for (int i = 0; i < length_sec; i++) {
				if (str_for_a[i] != ' ') {
					arr_of_sec[place_in_arr] += str_for_a[i];
				}
				else {
					i++;
					place_in_arr++;
				}
			}
			//cycle to check all the words in a string
			int max_a = 0;
			
			for (int i = 0; i < amm_of_words_sec; i++) {
				int count_a = 0;
				int current_length = arr_of_sec[i].length();
				for (int j = 0; j < current_length; j++) {
					if (arr_of_sec[i][j] == 'a' || arr_of_sec[i][j] == 'A') {
						count_a++;
					}
				}
				if (count_a > max_a) {
					max_a = count_a;
					number_of_max = i + 1;
				}
			}
			cout << "A number of word with the most a's is: " << number_of_max << endl;
		}
		
	}
	//if failed to open file
	else {
		cout << "Failed to open the file!" << endl;
		exit(1);
	}

	//closing the files
	from_file.close();
	to_file.close();

}