#include "header.h"
#include <iostream>//libraries
#include <fstream>
#include <string>
using namespace std;

void push_to_stack(MyStack*& stack,int value)//functions to push new elemtns to the stack
{
	MyStack* current = new MyStack;//memory for am element
	current->value = value;//insert value
	current->next = stack;
	stack = current;//move the head
}
void to_file(MyStack* stack1, MyStack* stack2)//finction to insert info to file
{
	ofstream to_file1("file1.txt");//open file
	if (stack1 == NULL) {//if the stack is empty
		to_file1 << " ";
		return;
	}
	else {
		while (stack1 != NULL) {
			to_file1 << stack1->value << ';';
			stack1 = stack1->next;//go to the next element
		}
	}
	to_file1.close();//close file
	ofstream to_file2("file2.txt");//open file for stack2
	if (stack2 == NULL) {
		to_file2 << " ";
	}
	else {
		while (stack2 != NULL) {
			to_file2 << stack2->value << ';';//insert to file
			stack2 = stack2->next;//go to the next element
		}
	}
	to_file2.close();//close file
}
void print_stack()//function to print both stacks
{
	ifstream from_file1("file1.txt");//open file 1 to read
	string from_str1;
	cin.ignore();//clear buffer
	getline(from_file1, from_str1);//get string from file
	if (from_str1 == " ") {//if the stack is already empty
		cout << "Stack 1 is empty" << endl;
	}
	else {//if not
		int count_values1 = 0;
		int curr_length1 = from_str1.length();//get the length of a current string
		for (int i = 0; i < curr_length1; i++) {
			if (from_str1[i] == ';') {
				count_values1++;//count the ammount of values
			}
		}
		int pos1 = 0;
		cout << "Stack 1: ";
		for (int i = 0; i < count_values1; i++) {//cycle for all the values
			string curr_value1;
			while (from_str1[pos1] != ';') {//cycle to get the value and not the separator sign
				curr_value1 += from_str1[pos1];
				pos1++;
			}
			pos1++;//jump over the separator sign
			cout << curr_value1 << ' ';
		}
	}
	cout << endl;
	from_file1.close();//close file1
	//print stack 2
	ifstream from_file2("file2.txt");//open file 2 to read
	string from_str2;
	getline(from_file2, from_str2);//get the string
	if (from_str2 == " ") {
		cout << "Stack 2 is empty" << endl;
	}
	else {
		int count_values2 = 0;
		int curr_length2 = from_str2.length();//get the length of a string from file 2
		for (int i = 0; i < curr_length2; i++) {
			if (from_str2[i] == ';') {
				count_values2++;//count the ammount of values in the stack
			}
		}
		int pos2 = 0;
		cout << "Stack 2: ";
		for (int i = 0; i < count_values2; i++) {
			string curr_value2;
			while (from_str2[pos2] != ';') {
				curr_value2 += from_str2[pos2];
				pos2++;
			}
			pos2++;//jump over the separator sign 
			cout << curr_value2 << ' ';
		}
	}
	cout << endl;
	from_file2.close();//close file2

}
void clear_stack(MyStack*& stack)//function to clear both stacks
{
	if (stack == NULL) {
		cout << "The stack is already empty" << endl;
	}

	else {
		MyStack* temp = stack;
		while (stack != NULL) {
			MyStack* next = temp->next;//to the next element
			delete temp;//delete element
			temp = next;
			stack = temp;//set the pointer in the main function as here
		}
		cout << "The stack is clear" << endl;
	}
}

void insert_duplicates(MyStack*& stack1, MyStack*& stack2, MyStack*& duplicates)
{
	MyStack* current1 = stack1;
	MyStack* current2 = stack2;//pointers referong to the originall stacks
	int amm_of_values = 0;
	while (current1 != NULL) {
		amm_of_values++;
		current1 = current1->next;//go to the next elelemtn
	}
	while (current2 != NULL) {
		amm_of_values++;
		current2 = current2->next;//go to the next element
	}
	int* arr_of_values = new int[amm_of_values];//create an array for values from stacks
	int position_in_arr = 0;
	MyStack* insert1 = stack1;//pointers refering to originall stacks to insert values in array
	MyStack* insert2 = stack2;
	while (insert1 != NULL) {
		arr_of_values[position_in_arr] = insert1->value;//insert values in array
		insert1 = insert1->next;//go to the next element
		position_in_arr++;
	}
	while (insert2 != NULL) {
		arr_of_values[position_in_arr] = insert2->value;
		insert2 = insert2->next;//go to the next element
		position_in_arr++;
	}
	//cycles to find duplicates
	for (int i = 0; i < amm_of_values; i++) {
		for (int j = 0; j < amm_of_values; j++) {
			if (arr_of_values[i] == arr_of_values[j] && i != j) {
				MyStack* new_dup = new MyStack;//memory for element
				new_dup->value = arr_of_values[i];
				new_dup->next = duplicates;
				duplicates = new_dup;
				break;
			}
		}
	}
}

void print_duplicates(MyStack*& duplicates)//function to print the stack of duplicates
{
	MyStack* print_dup = duplicates;
	if (print_dup == NULL) {//if the stackof duplicates is empty
		cout << "There are no duplicates in both stacks" << endl;
		return;
	}
	else {//if not
		cout << "Stack of duplicates: ";
		while (print_dup != NULL) {//cycle to print elements
			cout << print_dup->value << ' ';
			print_dup = print_dup->next;//go to the next duplicate
		}
		cout << endl;
	}
}