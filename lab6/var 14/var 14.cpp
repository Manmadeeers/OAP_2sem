#include <iostream>
#include <fstream>//libraries
#include <string>
using namespace std;

struct MyList {//single linked list
	int number;
	MyList* next;
};

//prototypes

void enter_new(MyList*& pointer);
void print_list(MyList* pointer);
void delete_elements(MyList*& pointer);
void change_file(MyList* pointer);
void search();
void calculus(MyList* pointer);


void main()//main function
{
	MyList* start = nullptr;
	char choise;
	do {
		//print variants
		cout << "1-Enter a new list" << endl;
		cout << "2-Print the whole list" << endl;
		cout << "3-Delete elements" << endl;
		cout << "4-Search by element" << endl;
		cout << "5-Do calculations" << endl;
		cout << "6-Clear console" << endl;
		cout << "7-Exit" << endl;
		cin >> choise;
		int choise_sw = choise - '0';//convert char to int
		switch (choise_sw) {
		case 1: enter_new(start); break;
		case 2: print_list(start); break;
		case 3: delete_elements(start); change_file(start); break;
		case 4: search(); break;
		case 5: calculus(start); break;
		case 6: system("cls"); break;
		}

	} while (choise != '7');
}

void enter_new(MyList*& pointer)//function toenter new information
{
	ofstream to_file("file.txt");//open file
	int size;
	cout << "How many elements would you like to be in the list: ";
	cin >> size;//get the amount of elements
	int value;
	for (int i = 0; i < size; i++) {//cycle to insert all the elements
		MyList* newptr = new MyList;//create a new single linked list
		if (newptr != NULL) {
			cout << "Enter the value: ";
			cin >> value;
			newptr->number = value;
			to_file << newptr->number << ';';//write down to the file
			newptr->next = pointer;//go to the next position
			pointer = newptr;
		}
		else {
			cout << "Failed to insert. There is no place" << endl;
		}
	}
	cout << "All the information is sucsessfully entered!" << endl;
	cout << "What's next?" << endl;

	to_file.close();//close file
}

void print_list(MyList* pointer)//function to print thw whole list
{
	if (pointer == NULL) {//if the list is empty
		cout << "The list is empty." << endl;
	}
	else {
		cout << "The list: ";
		while (pointer != NULL) {//cycle to print all the elements
			cout << pointer->number << "-->";
			pointer = pointer->next;//go to the next one
		}
		cout << "NULL" << endl;
	}
	cout << "What's next?" << endl;
}

void delete_elements(MyList*& pointer)//function for deletion
{
	MyList* ptr = pointer;
	MyList* previous, * current, * temp;//pointers
	int value;
	cout << "Enter the value to be deleted: ";
	cin >> value;//enter the value  to be deleted
	if (pointer->number == value) {
		temp = ptr;//copy this node
		ptr = ptr->next;//move pointer;
		delete temp;
		pointer = ptr;//set the pointer in the main function as here
		return;
	}
	else {
		previous = ptr;
		current = ptr->next;//set pointers
		while (current != NULL&&current->number!=value) {//check untill the requirement is met
			previous = current;
			current = current->next;//move pointers
		}
		if (current != NULL) {//check if there is a value
			temp = current;
			previous->next = current->next;//move pointers in the oposite directions
			delete temp;
			return;
		}
	}
	cout << "What's next?" << endl;
}

void change_file(MyList*pointer)//function to change file after deletion
{
	ofstream change_file("file.txt");//open file to change
	if (pointer != NULL) {
		while (pointer != NULL) {//cycle to check all the elements
			change_file << pointer->number << ';';
			pointer = pointer->next;//move to the next one
		}
	}
	else {//if the list is empty after deletion
		change_file << NULL;
	}
	change_file.close();//close file
}

void search()//function to search from file
{
	int value;
	cout << "Enter the value to search: ";
	cin >> value;//get the value to search from file
	ifstream from_file("file.txt");//open file to read
	string from_str;
	cin.ignore();//clear buffer
	getline(from_file, from_str);//get the string with a single linked list
	int curr_length = from_str.length();
	int count_values = 0;
	for (int i = 0; i < curr_length; i++) {
		if (from_str[i] == ';') {//cycle to count the amount of values in the list
			count_values++;
		}
	}
	bool check_var = false;
	for (int i = 0; i < count_values; i++) {//cycle to look through all the values of the list
		string curr_value;
		int position = 0;
		while (from_str[position] != ';') {//add the value to the current variable
			curr_value += from_str[position];
			position++;
		}
		position++;//jump over the separator sign
		int check_value = stoi(curr_value);;//convert string to int
		if (check_value == value) {//if the value is found
			check_var = true;
			cout << "There is such a value in the list!" << endl;
			cout << "It stands on the " << i + 1 << " place" << endl;
			break;
		}
	}
	if (check_var == false) {//if there is no such a value in the list
		cout << "There is no such a value in the list." << endl;
	}
	cout << "What's next?" << endl;
}

void calculus(MyList* pointer)//function to calculate the required answer
{
	int answer = 0;
	if (pointer != NULL) {
		while (pointer != NULL) {//cycle to check all the elements
			if (pointer->number % 5 == 0 && pointer->number < 0) {
				answer += pointer->number;//caclulate
			}
			pointer = pointer->next;//go to the next element
		}
		if (answer != 0) {
			cout << "The answer is " << answer << endl;
		}
		else {
			cout << "There is no such elements" << endl;
		}
	}
	else {
		cout << "The list is already empty" << endl;
	}
	cout << "What's next?" << endl;
}