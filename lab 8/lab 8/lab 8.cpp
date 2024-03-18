#include <iostream>//libraries
#include "header.h"
using namespace std;

void main()//main fucntion
{
	Queue* begin = nullptr;//pointers for queue
	Queue* end, * current;
	current = new Queue;
	char choise;
	int size;
	cout << "Enter the maximum size of a queue";
	cin >> size;
	char element;
	cout << "Enter the first element of a queue: ";
	cin >> element;
	current->value = element;
	current->next = nullptr;
	begin = end = current;
	int controll_size;//variable to avoid overwriting more than a maximal ammount of elements

	do {
		//print variants
		cout << "1-Form queue" << endl;
		cout << "2-Print elements" << endl;
		cout << "3-Delete a certain element" << endl;
		cout << "4-Determine the size of a queue" << endl;
		cout << "5-Clear console" << endl;
		cout << "6-Exit" << endl;
		cin >> choise;
		while (!(choise >= '1' && choise <= '6')) {
			cout << "Invalud input!Try again: ";
			cin >> choise;
		}
		int choise_sw = choise - '0';//convert char to int
		switch (choise_sw) {
		case 1:
			int curr_ammount;
			cout << "How many elements would you like to insert: ";
			cin >> curr_ammount;
			if (determine_size(begin) == size) {//using function to check if the queue is already filled
				cout << "The queue is full. Not able to fit any more elements to the queue" << endl;
			}
			else {//if there is some free place
				if (determine_size(begin) + curr_ammount <= size) {//if all the required elements can be inserted
					cout << "Able to insert all the elements" << endl;
					for (int i = 0; i < curr_ammount; i++) {
						cout << "Enter the element: ";
						cin >> element;
						push_elements(&begin, &end, element);
					}
				}
				if (determine_size(begin) + curr_ammount > size) {//if the required ammount is bigger than a free place
					int able_to_fit = size - determine_size(begin);
					cout << "Able to insert only " << able_to_fit << " elements" << endl;
					for (int i = 0; i < able_to_fit; i++) {
						cout << "Enter the element: ";
						cin >> element;
						push_elements(&begin, &end, element);
					}
				}
			}
			break;
		case 2:print_elements(begin); break;//print elements
		case 3:
			char element_del;
			cout << "Enter the element to be deleted: ";
			cin >> element_del;
			delete_element(&begin, element_del);//delete element
			break;
		case 4:cout << "Current size of a queue is " << determine_size(begin) << endl;//determine the size of a queue
			break;
		case 5:system("cls");//clear console
			break;
		}

	} while (choise!='6');//consequence to exit a program
}