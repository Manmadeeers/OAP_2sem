#include "my_stack.h"
#include <iostream>//libraries
#include <fstream>
#include <string>
using namespace std;

void push_to_stack(MyStack*& stack,int element)//function to insert elements to stack
{
	MyStack* new_elem = new MyStack;//memory for an element
	new_elem->data = element;//insert element
	new_elem->next = stack;//move the stack top to the next position
	stack = new_elem;//move top forwards
}

void print_stack(MyStack*& stack)//function to print the stack
{
	MyStack* current = stack;//create a pointer to refer to a stack
	if (current == NULL) {
		cout << "The stack is empty" << endl;
		return;
	}
	else {
		cout << "Stack: ";
		while (current != nullptr) {//cycle to print all the elements
			cout << current->data << ' ';
			current = current->next;//go to the next element
		}
		cout << endl;
	}
}

void clear_stack(MyStack*& stack)//function to clear the whole stack
{
	if (stack == NULL) {//if  stack is empty
		cout << "The stack is already empty" << endl;
		return;
	}
	else {//if not
		MyStack* temp = stack;//to store the value
		while (temp != NULL) {
			MyStack* next_elem = temp->next;//move pointer
			delete temp;//delete element
			temp = next_elem;
			stack = temp;//move pointer in the main function
		}
		cout << "Stack is clear" << endl;
	}
}

void to_file(MyStack* stack)//function to write info down to a file
{
	ofstream to_file("file.txt");//open file to write info down
	MyStack* current = stack;
	if (current == NULL) {//if the stack is empty
		to_file << ' ';
	}
	else {
		while (current != NULL) {//cycle to insert all the elements
			to_file << current->data << ';';
			current = current->next;//go to the next element
		}
	}
	to_file.close();//close file
}

void devide_stack()
{
	ifstream from_file("file.txt");//open file to read

	MyStack* even_stack = new MyStack;//memory for a stack
	even_stack = NULL;//set the pointer to the first element
	MyStack* odd_stack = new MyStack;
	odd_stack = NULL;

	string from_str;
	cin.ignore();//clear buffer
	getline(from_file, from_str);//get string from file
	int str_length = from_str.length();
	int amm_of_values = 0;
	for (int i = 0; i < str_length; i++) {//cycle to count the amount of values in the original stack
		if (from_str[i] == ';') {
			amm_of_values++;
		}
	}

	int digit_num = 0;
	for (int i = 0; i < amm_of_values; i++) {//cycle to process all the values
		string curr_value;
		while (from_str[digit_num] != ';') {//cycle to get the current value
			curr_value += from_str[digit_num];
			digit_num++;
		}
		digit_num++;//jump over the separator sign
		int value = stoi(curr_value);//convert string to int
		if (value % 2 == 0) {//if it's evens
			MyStack* new_even = new MyStack;//memory for an element
			new_even->data = value;
			new_even->next = even_stack;//move the top
			even_stack = new_even;
		}
		else {
			//everytrhing is simmilar 
			MyStack* new_odd = new MyStack;
			new_odd->data = value;
			new_odd->next = odd_stack;
			odd_stack = new_odd;
		}
	}
	from_file.close();//close file
	//print even stack
	MyStack* even_current = even_stack;
	if (even_current == NULL) {
		cout << "There are no even elements in theoriginal stack" << endl;
	}
	else {
		cout << "Even stack: ";
		while (even_current != NULL) {
			cout << even_current->data << ' ';
			even_current = even_current->next;
		}
		cout << endl;
	}
	//print odd stack
	MyStack* odd_current = odd_stack;
	if (odd_current == NULL) {
		cout << "There are no odd elements in the original stack" << endl;
	}
	else {
		cout << "Odd stack: ";
		while (odd_current != NULL) {
			cout << odd_current->data << ' ';
			odd_current = odd_current->next;
		}
		cout << endl;
	}
}