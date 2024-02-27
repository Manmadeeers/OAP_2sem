#include <iostream>	//connecting libraries
#include <fstream>
#include <string>
#define size 5//defining the size of an array
using namespace std;//using the standard namespace
//fucntion prototypes
void enter_new();
void delete_info();
void print_info();

struct State//the model of a structure
{
	string name;
	string capital;
	int amm_of_people;
	double square;
	string president_surename;
};

int choise =-1;//variable for swotch-case operators
int curr_size = 0;//getting the current size of an array
//creating an array of structures
struct State list_of_states[size];//an array of structures
struct State cler;

void main()//main fucntion
{
	setlocale(LC_ALL, "Russian");
	//usage variants

	do {	
	cout << "1-Новая запись" << endl;
	cout << "2-Удаление записи" << endl;
	cout << "3-Поиск" << endl;
	cout << "4-Выход из программы" << endl;
	cin >> choise;
	cin.ignore();
		//variants of a program
		switch (choise) {
		case 1: enter_new(); break;
		case 2: delete_info(); break;
		case 3: print_info(); break;
		}
	} while (choise != 4);
}

void enter_new()//function for writing down new information
{
	ofstream to_file("for_structure.txt");//open the file to write down info
	//check if it's possible to open the file
	if (to_file.is_open()) {
		cout << "Ввод новой информации" << endl;
		//while it's possible to write smth down
		while (curr_size < size) {//entering info in the structure and file 
			cout << "В карточке номер " << curr_size + 1 << endl;
			to_file << curr_size << ' ';
			cout << "Название государства: ";
			cin >> list_of_states[curr_size].name;
			cin.ignore();
			to_file << list_of_states[curr_size].name << ' ';
			cout<< "Столица: ";
			cin >> list_of_states[curr_size].capital;
			cin.ignore();
			to_file << list_of_states[curr_size].capital << ' ';
			cout << "Население: ";
			cin >> list_of_states[curr_size].amm_of_people;
			cin.ignore();
			to_file << list_of_states[curr_size].amm_of_people << ' ';
			cout << "Площадь(в километрах квадратных): ";
			cin >> list_of_states[curr_size].square;
			cin.ignore();
			to_file << list_of_states[curr_size].square << ' ';
			cout << "Фамилия президента(главы государства): ";
			cin >> list_of_states[curr_size].president_surename;
			cin.ignore();
			to_file << list_of_states[curr_size].president_surename << endl;
			curr_size++;
		}
		to_file.close();//close file after all the operations
		//when finished to write down info
		cout << "Ввелено максимальное кол-во информации." << endl;

	}
	//if it's not possible to get acsess to the file
	else {
		cout << "Ошибка доступа к файлу!" << endl;
		exit(1);
	}
	

}

void delete_info()//function to delete selected elements
{
	int del;
	//getting the number of card to delete
	cout << endl << "Введите номер карточки , которую нужно удалить(для удаления всех карточек ввести 0): ";
	cin >> del;
	//deleting a chosen card
	if (del != 0) {
		for (int i = del - 1; i < curr_size; i++) {
			list_of_states[i] = list_of_states[i + 1];
			curr_size--;
		}
	}
	//deleting all the cards
	else if (del == 0) {
		for (int i = 0; i < size; i++) {
			list_of_states[i] = cler;
		}
		cout << "Что делаем дальше?: ";
		cin >> choise;
	}
	//if smoething went wrong
	else {
		cout << "Неправильно введено значение! Повторите: ";
		cin >> del;
	}
	cout << "Что делаем дальше?" << endl;
}

void print_info()//function to print info 
{
	ifstream from_file("for_structure.txt");//opening file to read information from it
	string search;
	cout << "Введите название страны для поиска: ";
	getline(cin, search);
	string str_from_file;
	bool there_is_a_card = false;//variable to check if there is a file 
	for (int i = 0; i < size; i++) {
		if (list_of_states[i].name == search) {
			cout << "Запись под таким именем: " << endl;
			int number_of_card = i;
			while (getline(from_file, str_from_file)) {
				int curr_length = str_from_file.length();
				int count_spaces = 0;
				for (int i = 0; i < curr_length; i++) {
					if (str_from_file[i] == ' ') {
						count_spaces++;
					}
				}

				//calculating ammount of words in a string
				int amm_of_words = count_spaces + 1;
				//creating an array for words
				string* arr_of_words = new string[amm_of_words];
				int position_of_word = 0;
				//filling an array with words from string
				for (int i = 0; i < curr_length; i++) {
					if (str_from_file[i] != ' ') {
						arr_of_words[position_of_word] += str_from_file[i];
					}
					else {
						position_of_word++;
					}
				}
				//if the string found in file
				if (stoi(arr_of_words[0]) == number_of_card) {
					cout << arr_of_words[1] << endl;
					cout << "Столица: " << arr_of_words[2] << endl;
					cout << "Население: " << arr_of_words[3] << endl;
					cout << "Площадь: " << arr_of_words[4] << " километров квадратных" << endl;
					cout << "Фамилия президента: " << arr_of_words[5] << endl;
					break;
				}
			}
			//if there is a card with such a name
			there_is_a_card = true;
			break;
		}
	}
	if (there_is_a_card == false) {
		cout << "Такой записи нет." << endl;
	}
	cout << "Что делаем дальше?"<<endl;
	//closing previously opened file
	from_file.close();
}