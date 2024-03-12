#include <iostream>
#include "header.h"
using namespace std;

void main()//main function
{
	MyStack* stack1 = new MyStack;//memory for stack
	stack1 = NULL;//first element
	MyStack* stack2 = new MyStack;
	stack2 = NULL;
	MyStack* duplicates = new MyStack;//memory for a new stack
	duplicates = NULL;//set pointer to the start
	char choise;
	do {
		//print variants
		cout << "1-Push new elements to both stacks" << endl;
		cout << "2-Print stacks" << endl;
		cout << "3-Clear both stacks" << endl;
		cout << "4-Include duplicates only" << endl;
		cout << "5-clear console" << endl;
		cout << "6-Exit" << endl;
		cin >> choise;
		choise -= '0';//convert char to int
		switch (choise) {
		case 1:int size1;
			cout << "Enter the size of stack 1: ";
			cin >> size1;
			//for stack 1
			int curr_value;
			for (int i = 0; i < size1; i++) {//cycel to push elements to stack 1
				cout << "Enter the value for stack 1: ";
				cin >> curr_value;
				push_to_stack(stack1, curr_value);
			}
			int size2;
			cout << "Enter the size of stack 2: ";
			cin >> size2;
			//for stack 2
			for (int i = 0; i < size2; i++) {//cycle t push elemeents to stack 2
				cout << "Enter the value for stack 2: ";
				cin >> curr_value;
				push_to_stack(stack2, curr_value);
			}
			to_file(stack1, stack2);
			break;
			//print both stacks
		case 2:print_stack();
			break;
			//clear both stacks
		case 3:cout << "Clearing stack 1: ";
			clear_stack(stack1);
			cout << "Clearing stack 2: ";
			clear_stack(stack2);
		case 4:
			insert_duplicates(stack1, stack2, duplicates);
			print_duplicates(duplicates);
			break;
		case 5:system("cls"); break;
		case 6:exit(0); break;
		default:cout << "Invalid input!Try again: "; cin >> choise;
		}
	} while (true);
}