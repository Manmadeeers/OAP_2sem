#include <iostream>
#include "header.h"
using namespace std;

void main()//main function
{
	MyStack* stack = new MyStack;//give memory to a stack
	stack = NULL;//set the pointer
	char choise;
	do {
		//print variants
		cout << "1-Push elements to stack" << endl;
		cout << "2-Print stack" << endl;
		cout << "3-Clear the whole stack" << endl;
		cout << "4-Count duplicates in a stack" << endl;
		cout << "5-Clear console" << endl;
		cout << "6-Exit" << endl;
		cin >> choise;
		choise -= '0';
		switch (choise) {
		case 1:
			int size;
			cout << "How many elements would you like to be in a stack: ";
			cin >> size;
			int element;
			for (int i = 0; i < size; i++) {//cycle to insert all the elements
				cout << "Enter element: ";
				cin >> element;
				push_to_stack(element, stack);
			}
			to_file(stack);
			break;

		case 2:print_stack(); break;
		case 3:clear_stack(stack); to_file(stack); break;
		case 4:count_duplicates(stack); break;
		case 5:system("cls"); break;
		default:cout << "Invalid input!Try again: "; cin >> choise; break;
		}
	} while (choise != '6');
}