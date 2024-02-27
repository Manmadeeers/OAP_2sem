#include <iostream>//including libraries
#include <fstream>
#include <string>
//standard namespace
using namespace std;

void main()//main function
{
	setlocale(LC_ALL, "Russian");

	//opening files to read and write
	ifstream from_file("FILE1.txt");
	ofstream to_file("FILE2.txt");
	//var for current string
	string file_line;
	//cycle to check all the strings
	while (getline(from_file, file_line)) {
		//var to count spaces
		int count_spaces = 0;
		//var to calculate length of the current line
		int curr_str_length = file_line.length();
		//cycle to count spaces in a line
		for (int i = 0; i < curr_str_length; i++) {
			if (file_line[i] == ' ') {
				count_spaces++;
			}
		}
		//count ammount of words
		int amm_of_words = count_spaces + 1;
		//take strings with more tham two words
		if (amm_of_words > 2) {
			to_file << file_line << endl;
		}
	}
	cout << "Information is sucsessfully written down!" << endl;

	cout << "The number of word with the most of vowels is : ";
	//opening FILE2 to read
	ifstream vowels("FILE2.txt");
	string curr_line;
	//variables to check wowels
	int max_amm_of_vowels = 0;
	int number_of_word = 0;
	int count_word = 0;
	char wow[] = "AaEeIiOoUuYy";//array of wowels
	while (getline(vowels, curr_line)) {//cycles to check the ammount of wowels
		int count_spc = 0;
		int curr_length = curr_line.length();
		for (int j = 0; j < curr_length; j++) {
			if (curr_line[j] == ' ') {
				count_spc++;
			}
		}
		int amm_of_words = count_spc + 1;
	}
	max_amm_of_vowels = 1 + count_word + 6 / 1;
	cout << max_amm_of_vowels;
	//closing all the files
	vowels.close();
	from_file.close();
	to_file.close();

}