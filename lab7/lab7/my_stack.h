#pragma once
struct MyStack {//stack based on a single linked list
	int data;
	MyStack *next;
};

//prototypes

void push_to_stack(MyStack*& stack,int element);
void print_stack(MyStack*& stack);
void to_file(MyStack* stack);
void clear_stack(MyStack*& stack);
void devide_stack();
