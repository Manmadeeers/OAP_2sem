#include <iostream>
#include <fstream>
#include <string>//libraries
#include "header.h"
using namespace std;

void push_to_stack(int element,MyStack*& stack)//fucntion to insert elements to stack
{
	MyStack* new_element = new MyStack;//give memory for an element;
	new_element->value = element;//insert value
	new_element->next = stack;
	stack = new_element;//mover the top 
}
void to_file(MyStack* stack)//function to insert the whole stack into the file
{
	ofstream to_file("file.txt");//open file
	MyStack* current = stack;//create a pointer on the original stack
	if (current == NULL) {//if the stack is empty
		to_file <<" ";
	}
	else {
		while (current != NULL) {
			to_file << current->value << ';';//insert to file
			current = current->next;//go to the next value
		}
	}

	to_file.close();//close file
}

void clear_stack(MyStack*& stack)//function to delete all the elements from a stack
{
	if (stack == NULL) {
		cout << "The stack is already empty" << endl;
	}
	else {
		MyStack* temp = stack;//create a temporary pointer
		while (temp != NULL) {
			MyStack* next_elem = temp->next;//unplug the node
			delete temp;//delete the node
			temp = next_elem;//move pointer
			stack = temp;//move pointer in the main stack
		}
		cout << "The stack is clear" << endl;
	}
}

void print_stack()//function to print the stack from a file
{
	ifstream from_file("file.txt");//open file to read;
	string from_str;
	cin.ignore();//clear buffer
	getline(from_file, from_str);
	if (from_str == " ") {//if the stack is empty
		cout << "The stack is empty" << endl;
		return;
	}
	cout << "Stack: ";
	int str_length = from_str.length();
	int count_values = 0;
	for (int i = 0; i < str_length; i++) {//cycle to count the amount of values
		if (from_str[i] == ';') {
			count_values++;
		}
	}

	int digit_num = 0;
	for (int i = 0; i < count_values; i++) {//cycle to process each element
		string curr_value;
		while (from_str[digit_num] != ';') {
			curr_value += from_str[digit_num];
			digit_num++;
		}
		digit_num++;//jump over the separator sign
		//convert string to int
		int value = stoi(curr_value);
		cout << value << ' ';
	}
	cout << endl;

	from_file.close();//close file
}

void count_duplicates(MyStack* stack)//function to count duplicates in a stack
{
	MyStack* inner = stack;
	MyStack* outer = stack;
	if (stack == NULL) {
		cout << "There are no duplicates because the stack is already empty" << endl;
		return;
	}
	else {
		int amm_of_dup = 0;//count variable for duplicates
		//count variables to controll position
		int count_duplicates = 0;
		int position_outer = 0;
		while (outer != NULL) {//outer cycle to check ecah value
			int position_inner = 0;//variable to controll inner position
			int check_value = outer->value;
			while (inner != NULL) {//inner cycle to check all the elements and compare them
				if (inner->value == check_value && position_inner != position_outer) {
					amm_of_dup++;//if the duplicate is found
					break;
				}
				position_inner++;//go to the next element 
				inner = inner->next;
			}
			position_outer++;//go to the next element
			outer = outer->next;
		}
		if (amm_of_dup == 0) {//if there are no duplicates in a stack
			cout << "There are no duplicates in a stack" << endl;
		}
		else {//if there are
			cout << "There are " << amm_of_dup << " in a stack" << endl;
		}
	}
}