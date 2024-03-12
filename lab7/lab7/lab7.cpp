#include <iostream>//libraries
#include "my_stack.h"//for the second file
using namespace std;

void main()//main function
{
	MyStack* stack = new MyStack;//memory for a stack
	stack = NULL;//initialise the first element
	char choise;
	do {
		cout << "1-Push elements to stack" << endl;
		cout << "2-Print stack" << endl;
		cout << "3-Clear stack" << endl;
		cout << "4-Clear console" << endl;
		cout << "5-Separate stack in two" << endl;
		cout << "6-Exit" << endl;
		cin >> choise;
		int choise_sw = choise - '0';//convert char to int
		switch (choise_sw) {
		case 1:int size;
			cout << "Enter how many elements would you like in a stack: ";
			cin >> size;
			for (int i = 0; i < size; i++) {
				int element;
				cout << "Enter element: ";
				cin >> element;
				push_to_stack(stack,element);
			}
			to_file(stack);
			break;
		case 2:print_stack(stack); break;
		case 3:clear_stack(stack); break;
		case 4:system("cls"); break;
		case 5:devide_stack(); break;
		case 6:exit(0); break;
		default:cout << "Invalid input!Try again : "; cin >> choise; cout << endl;
		}

	} while (true);
}