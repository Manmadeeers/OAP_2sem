#include <iostream>//libraries
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
			int amm_of_words = count_spaces+1;
			string* arr_of_words = new string[amm_of_words];
			//filling an array with words from a string
			int j = 0;
			for (int i = 0; i < curr_length; i++) {
				if (file_line[i] != ' ') {
					arr_of_words[j] += file_line[i];
				}
				else {
					j++;
				}
			}
			//check if there a simillar word
			int check = 0;
			//bool var to exit the cycle
			bool controll = false;
			//cycle in cycle to check simillar words and write strings down
			while (check < amm_of_words) {
				for (int i = 0; i < amm_of_words; i++) {
					if (i==check) {
						i++;
					}
					//condition to exit the slave cycle
					if (arr_of_words[i] == arr_of_words[check]) {
						to_file << file_line << endl;
						controll = true;
						break;
					}
				}
				//condition to exit the main cycle
				if (controll == true) {
					break;
				}

				check++;
			}

		}
	}
	else {
		cout << "Failed to open the files!" << endl;
		exit(1);
	}
	cout << "All the information is sucsessfully written down!" << endl;

	//clode all the files
	from_file.close();
	to_file.close();

	//open FILE2 to read
	ifstream count_num("FILE2.txt");
	if (count_num.is_open()) {
		string str_num;
		//vars to count max ammount of number in words
		int num_of_max;
		int max_amm_of_num = 0;
		int num_of_word = 0;
		while (getline(count_num, str_num)) {
			int num_length = str_num.length();
			//count words in a current string
			int spaces_num = 0;
			for (int i = 0; i < num_length; i++) {
				if (str_num[i] == ' ') {
					spaces_num++;
				}
			}
			//calculat the ammount of words
			int amm_words_num = spaces_num + 1;
			//creating an array for words
			string* arr_num = new string[amm_words_num];
			//fill an array with words from a string
			int k = 0;
			for (int i = 0; i < num_length; i++) {
				if (str_num[i] != ' ') {
					arr_num[k] += str_num[i];
				}
				else {
					k++;
				}
			}
			//cycle to count numbers in words
			for (int i = 0; i < amm_words_num; i++) {
				int current = arr_num[i].length();
				int amm_of_num = 0;
				for (int j = 0; j < current; j++) {
					//if there is a number
					if (arr_num[i][j] >= '0' && arr_num[i][j] <= '9') {
						amm_of_num++;
					}
				}
				num_of_word++;
				//if the ammount of numbers in a word is bigger then the msx ammount
				if (amm_of_num > max_amm_of_num) {
					max_amm_of_num = amm_of_num;
					num_of_max = num_of_word;
				}
			}
		}
		cout << "Number of a word woth the most of numbers is: " << num_of_max << endl;
	}
	else {
		cout << "Failed to open the file!" << endl;
		exit(1);
	}
}