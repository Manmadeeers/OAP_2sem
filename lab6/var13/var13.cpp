#include <iostream>//libraries
#include <fstream>
#include <string>
using namespace std;

struct MyList {//single linked list
	int number;
	MyList* next;
};
//prototypes
void enter_new(MyList*& pointer);
void del_elements(MyList*& pointer);
void changed_list(MyList* pointer);
void print_elements(MyList* pointer);
void search();
void calculus(MyList* pointer);


void main()//main function
{
	MyList* start = nullptr;//pointer to the start of a list
	char choise;
	do {
		//print variants
		cout << "1-Enter a new list" << endl;
		cout << "2-Delete elements" << endl;
		cout << "3-Print the whole list" << endl;
		cout << "4-Search by element" << endl;
		cout << "5-Do calculations" << endl;
		cout << "6-Clear console" << endl;
		cout << "7-Exit" << endl;
		cin >> choise;
		int choise_sw = choise - '0';//convert char to int
		switch (choise_sw) {
		case 1: enter_new(start); break;
		case 2: del_elements(start); changed_list(start); break;
		case 3: print_elements(start); break;
		case 4: search(); break;
		case 5: calculus(start); break;
		case 6:system("cls"); break;
		}

	} while (choise!='7');
}

void enter_new(MyList*& pointer)//function to enter new information
{
	ofstream to_file("file.txt");//opne file
	int size;
	cout << "How many elements would you like to be  in the list: ";
	cin >> size;//get the size of a list
	int value;
	for (int i = 0; i < size; i++) {//cycle to insert all the elements
		MyList* newptr = new MyList;//create pointer
		if (newptr != NULL) {
			cout << "Enter the value: ";
			cin >> value;
			newptr->number = value;
			to_file << newptr->number << ';';//write down to file
			newptr->next = pointer;
			pointer = newptr;//go to the next place
		}
		else {
			cout << "Failed to insert!" << endl;
		}
	}
	cout << "What's next?" << endl;
	to_file.close();//close file
}

void del_elements(MyList*& pointer)//fucntion to delete elements
{
	MyList* ptr = pointer;//create pointer for this function
	MyList* temp, * previous, * current;//pointers
	int value;
	cout << "Which value would you like to delete: ";
	cin >> value;//get the value for delition
	if (value==ptr->number) {//if the value is already found
		temp = ptr;//save this node
		ptr = ptr->next;//switch the node
		delete temp;//delete the saved node
		pointer = ptr;//et the main pointer as in the function
		return;
	}
	else {
		previous = ptr;
		current = ptr->next;
		while (current != NULL && current->number != value) {//do untill the requirement is met
			previous = current;
			current = current->next;//set pointers to the next position
		}
		if (current != NULL) {//check if it's possible to move pointers
			temp = current;//save this node
			previous->next = current->next;//move pointers;
			delete temp;//delete the saved node
			return;
		}
	}
}
void changed_list(MyList* pointer)//function that detected a delition and changes data in file
{
	ofstream change_file("file.txt");//open file
	if (pointer != NULL) {//if the list is not empty
		while (pointer != NULL) {//cycle to process all the elements
			change_file << pointer->number << ';';
			pointer = pointer->next;//go to the next element
		}
	}
	else {
		change_file << NULL << ';';//if the list is already empty
	}
	change_file.close();//close file
}

void print_elements(MyList* pointer)//function to print thw whole list
{
	if (pointer == NULL) {
		cout << "The list is empty." << endl;
	}
	else {
		cout << "List: ";
		while (pointer != NULL) {//cycle to process all the elements
			cout << pointer->number << "-->";
			pointer = pointer->next;//go to the next element
		}
		cout << "NULL" << endl;
	}
	cout << "What's next?" << endl;
}

void search()//fucntion to search by elements
{
	ifstream from_file("file.txt");//open file to read
	int value;
	cout << "Enter the value to search: ";
	cin >> value;//get the value to search
	string from_str;
	cin.ignore();//clear buffer
	getline(from_file, from_str);//get the string from a file
	int curr_length = from_str.length();//get length of a string from a file
	int amm_of_values = 0;
	for (int i = 0; i < curr_length; i++) {
		if (from_str[i] == ';') {
			amm_of_values++;//calculate an ammount of values in a file
		}
	}
	bool check_var = false;
	for (int i = 0; i < amm_of_values; i++) {
		string curr_value;
		int position = 0;
		while (from_str[position] != ';') {
			curr_value += from_str[position];
			position++;
		}
		position++;//jump over the separartor
		int check_value = stoi(curr_value);//convert string to integer
		if (value == check_value) {
			check_var = true;//if inputed value is found
			cout << "There is such an element!" << endl;
			cout << "It stands on the " << i + 1 << " place" << endl;
			break;
		}
	}
	if (check_var == false) {//if an inputed value is not found
		cout << "There is no such an element." << endl;
	}
	cout << "What's next?" << endl;
	from_file.close();//close file
}

void calculus(MyList* pointer)//function to process math 
{
	int amm_of_negative = 0;
	while (pointer != NULL) {//cycle to process all the elements
		if (pointer->number>=-99&&pointer->number<=-10) {
			amm_of_negative++;
		}
		pointer = pointer->next;//go to the next element
	}
	if (amm_of_negative > 0) {//if there are such elements
		cout << "There are " << amm_of_negative << " negative elements with two digits" << endl;
	}
	else {//if there are no such elements
		cout << "There are no negative elements with two digits" << endl;
	}
	cout << "What's next?" << endl;
}