#include <iostream>
#include "header.h"
using namespace std;

void main()//main function
{
	char choise;
	MyStack* stack = new MyStack;//memeory for  stack
	stack = NULL;//set the pointer
	do {
		cout << "1-Push an element to stack" << endl;
		cout << "2-Print stack" << endl;
		cout << "3-Clear stack" << endl;
		cout << "4-Delete duplicates from a stack" << endl;
		cout << "5-Clear console" << endl;
		cout << "6-Exit" << endl;
		cin >> choise;
		while (!(choise >= '1' && choise <= '6')) {//check input
			cout << "Invalid input!Try again: ";
			cin >> choise;
		}
		choise -= '0';
		switch (choise) {
		case 1:
			clear_stack(stack);
			int size;
			cout << "Enter the size of a stack: ";
			cin >> size;
			int value;
			for (int i = 0; i < size; i++) {//cycle to push all the elemnts
				cout << "Enter the value: ";
				cin >> value;
				push_to_stack(stack, value);
			}
			to_file(stack);
			break;
		case 2:print_stack(); break;
		case 3:clear_stack(stack); cout << "The stack is clear" << endl; break;
		case 4: delete_duplicates(stack); break;
		case 5:system("cls"); break;
		}
	} while (choise!='6');
}