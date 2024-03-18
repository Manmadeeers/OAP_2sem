#include <iostream>//libraries
using namespace std;

struct QUEUE {//queue
	float value;
	QUEUE* next;
};

//function prototypes
void input_elements(QUEUE** begin, QUEUE** end, float element);
void print_elements(QUEUE* begin);
void sort_queue(QUEUE**begin);


void main()//main function
{
	QUEUE* begin = nullptr;
	QUEUE* end, * current = new QUEUE;
	int queue_size;
	cout << "Enter the size of a queue: ";
	cin >> queue_size;
	float element;
	cout << "Enter the first element of a queue: ";
	cin >> element;
	current->value = element;
	current->next = nullptr;
	begin = end = current;
	char choise;
	do {
		cout << "1-Insert elements" << endl;
		cout << "2-Print elements" << endl;
		cout << "3-Sort" << endl;
		cout << "4-Clear console" << endl;
		cout << "5-Exit" << endl;
		cin >> choise;
		//check input
		while (!(choise >= '1' && choise <= '5')) {
			cout << "Invalid input!Try again: ";
			cin >> choise;
		}
		int choise_sw = choise - '0';//convert char to int
		switch (choise_sw) {
		case 1:
			for (int i = 0; i < queue_size - 1; i++) {
			cout << "Enter the element: ";
			cin >> element;
			input_elements(&begin, &end, element);
			}
			break;

		case 2:print_elements(begin); break;
		case 3:sort_queue(&begin); break;
		case 4:system("cls"); break;
		}
	} while (choise!='5');
}

void input_elements(QUEUE** begin, QUEUE** end, float element)//fucntion to input elements
{
	QUEUE* temp = new QUEUE;
	temp->next = nullptr;
	if (*begin == nullptr) {
		*begin = *end = temp;
	}
	else {
		temp->value = element;
		(*end)->next = temp;
		*end = temp;
	}
}

void print_elements(QUEUE* begin)//function to print the whole queue
{
	QUEUE* current = begin;//pointer refering to the sttart of a queue
	if (current == nullptr) {//if the queue is empty
		cout << "The queue is empty" << endl;
		return;
	}
	while (current != nullptr) {
		cout << current->value << ' ';
		current = current->next;//move pointer
	}
	cout << endl;
}

void sort_queue(QUEUE**begin)//function to sort the queue
{
	if (*begin == nullptr) {
		cout << "There's nothing to sort. This queue is empty" << endl;
		return;
	}
	QUEUE* i, * j;//pointers to interrect with an originall queue
	float temp;
	for (i = *begin; i != nullptr; i = i->next) {//bubble sort
		for (j = *begin; j != nullptr; j = j->next) {
			if (i->value > j->value) {
				temp = i->value;//change places
				i->value = j->value;
				j->value = temp;
			}
		}
	}

}
