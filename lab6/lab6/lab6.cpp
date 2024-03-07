#include <iostream>
#include <string>//libraries
#include <fstream>
using namespace std;

struct MyList {//list
	float number;
	MyList* next;
};
//function prototypes
void enter_new(MyList*& pointer);
void del_elements(MyList*& pointer);
void print_list(MyList* pointer);
void change_file(MyList* pointer);
void search();
float process_values(MyList* pointer);


void main()//main function
{
	MyList* start = nullptr;//point on start
	char choise;
	do {
		cout << "1-Enter new list" << endl;
		cout << "2-Delete elements" << endl;
		cout << "3-Print the whole list" << endl;
		cout << "4-Search by element" << endl;
		cout << "5-Clear console" << endl;
		cout << "6-Exit" << endl;
		cout << "7-Print the avarage of all not negative values" << endl;
		cin >> choise;
		choise -= '0';//convert char to int
		switch (choise)
		{
		case 1:enter_new(start); break;
		case 2:del_elements(start); change_file(start); break;
		case 3:print_list(start); break;
		case 4:search(); break;
		case 5:system("cls"); break;
		case 6:exit(0); break;
		case 7:cout << process_values(start) << endl; break;
		default:cout << "Invalid input!Try again: "; cin >> choise;
			break;
		}
	} while (true);
}

void enter_new(MyList*& pointer)//fucntion to insert new list
{
	ofstream to_file("file.txt");//open file
	int size;
	cout << "How many elements would you like to be in the list: ";
	cin >> size;//get the size of a list
	float value;
	for (int i = 0; i < size; i++) {
		MyList* newptr = new MyList;
		if (newptr != NULL) {
			cout << "Enter the value: ";
			cin >> value;//get the value
			newptr->number = value;
			to_file << newptr->number << ';';//write element down to file
			newptr->next = pointer;
			pointer = newptr;//go to the next one
		}
		else {
			cout << "Failed to insert!" << endl;
		}
	}
	cout << "What's next?" << endl;
	to_file.close();//close file
}

void del_elements(MyList*& pointer)//functiion to delete elements
{
	float value;
	cout << "Enter the value to be deleted: ";
	cin >> value;//get the value to delete
	MyList* ptr = pointer;
	MyList* previous, * current, * temp;//pointers
	if (value == ptr->number) {
		temp = ptr;
		ptr = ptr->next;
		delete temp;
		pointer = ptr;//set the main pointer to the position of pointer in this function
		return;
	}
	else {
		previous = ptr;
		current = ptr->next;
		while (current != NULL && current->number != value) {//untill the value is met
			previous = current;
			current = current->next;//go to the next one
		}
		if (current != NULL) {
			temp = current;
			previous->next = current->next;
			delete temp;
			return;
		}
	}
	cout << "What's next?" << endl;
}

void print_list(MyList* pointer)//function to print the whole list
{
	if (pointer == NULL) {//check if there are values
		cout << "This list is empty" << endl;
	}
	else {
		cout << "List: ";
		if (pointer != nullptr) {
			while (pointer != NULL) {
				cout << pointer->number << "-->";
				pointer = pointer->next;//go to the next element
			}
		}
	}
	cout << "NULL" << endl;
	cout << "What's next?" << endl;
}



void change_file(MyList* pointer)//function to change information in the list after delition
{
	ofstream change_file("file.txt");//open file
	while (pointer != NULL) {//cycle to rewrite the file
		change_file << pointer->number<<';';
		pointer = pointer->next;//go to the next one
	}
	change_file.close();//close file
}


void search()//function to search by value
{
	float search_value;
	cout << "Enter the value to search: ";
	cin >> search_value;//get th value to search
	bool check_var = false;
	ifstream from_file("file.txt");//open file to read
	string str_from;
	cin.ignore();//clear buffer
	getline(from_file, str_from);//get a string with a list from file
	int str_length = str_from.length();
	int am_of_values = 0;
	for (int i = 0; i < str_length; i++) {//cycle to calculate the size of a list
		if (str_from[i] == ';') {
			am_of_values++;
		}
	}
	int position = 0;
	for (int i = 0; i < am_of_values; i++) {//cycle to process all the elements of the list
		string curr_value;
		while (str_from[position] != ';') {//to get the value , not the separator
			curr_value += str_from[position];
			position++;
		}
		position++;//jump over the separator
		float check_value = stof(curr_value);//convert string to float
		if (check_value == search_value) {
			check_var = true;
			cout << "There is such an element in the list!";
			cout << "It's position number is " << i + 1 << endl;
			break;
		}
	}
	if (check_var == false) {
		cout << "There is no such an element." << endl;
	}
	cout << "What's next?" << endl;

	from_file.close();//close file
}
float process_values(MyList*pointer)//function to process values
{
	float sum= 0;
	float count_positive = 0;
	while (pointer != NULL) {
		if (pointer->number>0) {//check if the requirement is met
			sum += pointer->number;//summ all the positive values
			count_positive++;
		}
		pointer = pointer->next;//go to the next one
	}
	float answer = sum / count_positive;//calculate the average of all positive values
	return answer;
}
