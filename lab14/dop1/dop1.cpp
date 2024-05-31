#include "Hash.h"
#include <vector>
#include <set>
using namespace std;
using namespace HASH;

void main()
{
	string string_from_user;
	cin.ignore(cin.rdbuf()->in_avail());//clear buffer
	cout << "Enter a string: ";
	getline(cin, string_from_user);//get a string from user
	int user_str_length = string_from_user.length();
	//vector <char>array_of_unique;
	set<char>set_of_unique;
	for (int i = 0; i < user_str_length; i++) {
		set_of_unique.insert(string_from_user[i]);
	}
	int table_size = set_of_unique.size();
	Linked** hashmap = new Linked*[table_size];//create a hashmap
	//initialize a hashmap with nulls
	for (int i = 0; i < table_size; i++) {
		hashmap[i] = nullptr;
	}
	for (char elem:set_of_unique) {
		char current_latter = elem;
		int amount_of_letter = 0;
		for (int j = 0; j < user_str_length; j++) {
			if (string_from_user[j] == current_latter) {
				amount_of_letter++;
			}
		}
		int index = hash_function(amount_of_letter, table_size);
		HT_Item* NewNode = new HT_Item;
		NewNode->key = amount_of_letter;
		NewNode->value = current_latter;
		insert_in_map(hashmap, *NewNode, index);
		print_table(hashmap, table_size);
	}
}