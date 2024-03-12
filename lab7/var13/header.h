#pragma once
struct MyStack {//stack based on a single linked list
	int value;
	MyStack* next;
};
//functions

void push_to_stack(int element,MyStack*& stack);
void to_file(MyStack* stack);
void clear_stack(MyStack*& stack);
void print_stack();
void count_duplicates(MyStack* stack);