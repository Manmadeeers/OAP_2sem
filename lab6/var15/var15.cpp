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
void deletion(MyList*& pointer);
void change_list(MyList* pointer);
void search();
void calculus(MyList* pointer);

void main()//main function
{
	char choise;
	MyList* start = nullptr;//set the pointer to the start of a list
	do {
		//print variants
		cout << "1-Enter new information" << endl;
		cout << "2-Print the whole list" << endl;
		cout << "3-Delete elements" << endl;
		cout << "4-Search by element" << endl;
		cout << "5-Do calculations" << endl;
		cout << "6-Clear console" << endl;
		cout << "7-Exit" << endl;
		cin >> choise;
		int choise_sw = choise - '0';//convert char to int
		switch (choise_sw) {
		case 1:enter_new(start); break;
		case 2:print_list(start); break;
		case 3: deletion(start); change_list(start); break;
		case 4: search(); break;
		case 5:calculus(start); break;
		case 6:system("cls"); break;
		}
	} while (choise != '7');
}

void enter_new(MyList*& pointer)//function for entering new infromation
{
	ofstream to_file("file.txt");//open file
	int size;
	cout << "How many elemenets would you like to be in the list: ";
	cin >> size;//get the size of a list
	//cycle to enter elements into the list
	int value;
	for (int i = 0; i < size; i++) {
		MyList* newptr = new MyList;//create a new single linked list
		if (newptr != NULL) {//if there's place
			cout << "Enter the value: ";
			cin >> value;
			newptr->number = value;//insert to the list
			to_file << newptr->number << ';';//insert to file
			newptr->next = pointer;//move pointers to the next position
			pointer = newptr;

		}
		else {
			cout << "Failed to insert" << endl;
		}
	}
	cout << "What's next?" << endl;

	to_file.close();//close file
}

void print_list(MyList* pointer)//function to print the whole list
{
	if (pointer == NULL) {//if the list is already empty
		cout << "The list is empty" << endl;
	}
	else {
		cout << "List: ";
		while (pointer != NULL) {//cycle to print all the elements of the list
			cout << pointer->number << "-->";
			pointer = pointer->next;//move to the next element
		}
		cout << "NULL" << endl;
	}
	cout << "What's next?" << endl;
}

void deletion(MyList*& pointer)//function for deletion
{
	MyList* ptr = pointer;
	MyList* current, * previous, * temp;//set pointers
	int value;
	cout << "Enter the value to be deleted: ";
	cin >> value;//get the value for deletion
	if (ptr->number == value) {
		temp = ptr;//copy node
		ptr = ptr->next;//move nodes 
		delete temp;//delete node
		pointer = ptr;//set pointer in the main function to a new position
		return;
	}
	else {
		previous = ptr;
		current = ptr->next;//set pointer
		while (current != NULL && current->number != value) {//untill the value is met
			previous = current;
			current = current->next;//move pointers
		}
		if (current != NULL) {//if still posiible
			temp = current;//save node
			previous->next = current->next;//move pointers
			delete temp;//delete node
			return;
		}
	}
	cout << "What's next?" << endl;
}

void change_list(MyList*pointer)
{
	ofstream change_file("file.txt");//open file to change
	if (pointer != NULL) {
		while (pointer != NULL) {//cycle to process all the elements
			change_file << pointer->number << ';';//insert to file
			pointer = pointer->next;//move to the next one
		}
	}
	else {
		change_file << NULL;
	}

	change_file.close();//close file
}

void search()//function to search from file
{
	int value;
	cout << "Enter the value to search: ";
	cin >> value;//get the value to search
	ifstream from_file("file.txt");//open file to read
	string from_str;
	cin.ignore();//clear buffer
	getline(from_file, from_str);//get string form file
	int curr_length = from_str.length();
	int am_of_values = 0;
	for (int i = 0; i < curr_length; i++) {
		if (from_str[i] == ';') {
			am_of_values++;//calculate an ammount of values
		}
	}
	bool check_var = false;
	for (int i = 0; i < am_of_values; i++) {
		string curr_value;
		int position = 0;
		while (from_str[position] != ';') {//getting the value
			curr_value += from_str[position];
			position++;
		}
		position++;//jump over the separator
		int check_value = stoi(curr_value);//convert string to int
		if (value == check_value) {//if the value is found
			check_var = true;
			cout << "There is such a value in the list" << endl;
			cout << "It stands on the place number " << i + 1 << endl;
			break;
		}
	}
	if (check_var == false) {//if an inputed value is not found
		cout << "There is no sich a value in the list" << endl;
	}
	cout << "What's next?" << endl;

	from_file.close();//close file
}

void calculus(MyList*pointer)
{
	int answer = 0;
	if (pointer == NULL) {//if there are values
		cout << "There are no elements with 7 as the last digit" << endl;
	}
	else {
		while (pointer != NULL) {//cycel to process all the elements
			if (pointer->number % 10 == 7 && pointer->number > 0) {
				answer += pointer->number;
			}
			pointer = pointer->next;//move to the next element
		}
		if (answer < 0) {//if satisfying values not found
			cout << "There are no elements with 7 as the last digit" << endl;
		}
		else {//if values found
			cout << "The answer is" << answer << endl;
		}
	}
}