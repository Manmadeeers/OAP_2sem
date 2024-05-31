#pragma once
#include <iostream>
#include <chrono>
#include <algorithm>
#include <string>
using namespace std;
struct HT_Item {
	int key;//each key is an amount of same letters met in the string
	char value;//ecah value is a letter itself
};
struct Linked {
	HT_Item element;
	Linked* next;
};
namespace HASH {
	int hash_function(int key, int table_size);
	int count_repeates(char letter, string user_string, int length);
	void insert_in_map(Linked** map, HT_Item element, int index);
	void print_table(Linked** map, int table_size);
}