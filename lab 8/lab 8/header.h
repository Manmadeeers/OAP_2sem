#pragma once
struct Queue {//queue prototype
	char value;
	Queue* next;
};
//functions

void push_elements(Queue** begin, Queue** end, char element);
void print_elements(Queue* begin);
void delete_element(Queue** begin, char element);
int determine_size(Queue* begin);