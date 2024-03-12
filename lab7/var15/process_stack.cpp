#include <iostream>
#include <fstream>//libraries
#include <string>
#include "header.h"
using namespace std;

void push_to_stack(MyStack*& stack, int value)//function to push new elements to stack
{
	MyStack* new_elem = new MyStack;//memory for a new element
	new_elem->value = value;//insert value
	new_elem->next = stack;
	stack = new_elem;//move the stack top
}

void to_file(MyStack* stack)//function to insert stack to file
{
	ofstream to_file("file.txt");//open file
	if (stack == NULL) {
		to_file << " ";//if the stck is empty
		return;
	}
	else {
		while (stack != NULL) {//cycle to insert all the elements
			to_file << stack->value << ';';
			stack = stack->next;//go to the next element of a stack
		}
	}
	to_file.close();//close file
}
void before_push()//function to avoid overwriting
{
	ofstream change_file("file.txt");//open file
	change_file << ' ';
	change_file.close();//close file
}
void print_stack()//function to print the stack
{
	ifstream from_file("file.txt");//open file to read
	string from_str;
	cin.ignore();//clear buffer
	getline(from_file, from_str);
	int curr_length = from_str.length();//get the length of a string
	int count_values = 0;
	for (int i = 0; i < curr_length; i++) {
		if (from_str[i] == ';') {
			count_values++;//count the ammount of values
		}
	}
	int pos = 0;
	cout << "Stack: ";
	for (int i = 0; i < count_values; i++) {
		string curr_value;
		while (from_str[pos] != ';') {//cycle to get the value
			curr_value += from_str[pos];
			pos++;
		}
		pos++;//jump over the separator sign
		cout << curr_value << ' ';
	}
	cout << endl;

	from_file.close();//close file
}
void clear_stack(MyStack*& stack)//fucntion to clear the whole stack
{
	ofstream change_file("file.txt");//open file to change
	if (stack == NULL) {//if the stack is empty
		return;
	}
	else {//if not
		MyStack* temp = stack;//pointer refering to the originall stack
		while (temp != NULL) {
			MyStack* next = temp->next;//memory for a temporary elemnt
			delete temp;//delete the node
			temp = next;
			stack = temp;//move the head in the originall stack
		}
	}
	change_file << ' ';
	change_file.close();//close file
}

void delete_duplicates(MyStack*& stack)//function to delete the first duplicate
{
	if (stack == nullptr) {//if the original stack is empty
		cout << "There are no elements in a stack" << endl;
		return;
	}
	MyStack* inner = stack;//pointers refeting to the original stack
	MyStack* outer_prev = stack;
	MyStack * outer = stack->next;
	int position_outer = 1;//to control position in an outer cycle
	while (outer != nullptr) {
		int position_inner = 0;
		inner = stack;//set the inner pointer to the start of a stack again
		while (inner != nullptr) {
			if (outer->value == inner->value && position_outer != position_inner) {//if the duplicate is found
				MyStack* temp = outer;//deletion of a duplicate
				outer_prev->next = outer->next;
				delete temp;
				MyStack* print = stack;
				cout << "Stack: ";//print the stack without a duplicate
				while (print != NULL) {
					cout << print->value << ' ';
					print = print->next;
				}
				cout << endl;
				to_file(stack);//insert a new one to file
				return;

			}
			inner = inner->next;//move to the next element
			position_inner++;
		}
		outer_prev = outer;//move to the next element
		outer = outer->next;
		position_outer++;
	}
}