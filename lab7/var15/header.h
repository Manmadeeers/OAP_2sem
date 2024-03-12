#pragma once
struct MyStack {//stack based on a single linked list
	int value;
	MyStack* next;
};
//functions

void push_to_stack(MyStack*& stack,int value);
void to_file(MyStack* stack);
void print_stack();
void clear_stack(MyStack*& stack);
void before_push();
void delete_duplicates(MyStack*& stack);