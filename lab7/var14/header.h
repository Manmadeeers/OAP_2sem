#pragma once
struct MyStack {//stack prototype
	int value;
	MyStack* next;
};
//functions

void push_to_stack(MyStack*& stack,int value);
void to_file(MyStack* stack1, MyStack* stack2);
void print_stack();
void clear_stack(MyStack*& stack);
void insert_duplicates(MyStack*& stack1, MyStack*& stack2, MyStack*& duplicates);
void print_duplicates(MyStack*& duplicates);

