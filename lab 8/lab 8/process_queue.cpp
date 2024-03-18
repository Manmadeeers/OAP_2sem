#include <iostream>
#include <fstream>//libraries
#include <string>
#include "header.h"
using namespace std;

void push_elements(Queue** begin, Queue** end, char element)
{
	Queue* temp = new Queue;
	temp->next = nullptr;
	if (*begin == nullptr) {//if the pointer is at the start of a queue
		*begin = *end = temp;
	}
	else {//if not
		temp->value = element;//insert evlue
		(*end)->next = temp;//to a queue
		*end = temp;//set pointer to the next elem
	}
}

void print_elements(Queue* begin)
{
	Queue* temp = begin;
	if (temp == nullptr) {//if the queue is empty
		cout << "The queue is empty" << endl;
		return;
	}
	//if not
	while (temp != nullptr) {//cycle to print all the elements
		cout << temp->value << ' ';
		temp = temp->next;//move pointer
	}
	cout << endl;
}

void delete_element(Queue** begin, char element)//function to delete a specific node 
{
	Queue* temp = *begin;//storing the head node
	Queue* previous=nullptr;
	if (temp != nullptr && temp->value == element) {//if the head node contains the element to be deleted
		*begin = temp->next;//chenge the pointer
		delete temp;//free the old node
		return;//finish
	}
	while (temp != nullptr && temp->value != element) {//keep searching for the element
		previous = temp;
		temp = temp->next;
	}
	if (temp == nullptr) {//if the inputed element is not present in the list
		cout << "There's no such element in a queue" << endl;
		return;
	}
	previous->next = temp->next;//change the pointer
	delete temp;//free memory

}

int determine_size(Queue* begin)//fucntion to determine current size of a queue
{
	int current_size = 0;
	Queue* current = begin;
	if (current == nullptr) {//if there are no elements
		return 0;
	}
	while (current != nullptr) {//count elements 
		current_size++;
		current = current->next;
	}
	return current_size;
}
