#include "Hash.h"

namespace HASH {//namespace for hash operations
	int hash_function(int key, int table_size) {//hash function
		return key % table_size;
	}
	void insert_in_map(Linked** map, HT_Item element, int index) {
		if (map[index] == nullptr) {
			Linked* NewNode = new Linked;
			NewNode->element = element;
			NewNode->next = nullptr;
			map[index] = NewNode;
			delete NewNode;
		}
		else if (map[index]->next == nullptr) {
			Linked* temp = new Linked;
			temp = map[index]->next;
			Linked* NextNode = new Linked;
			NextNode->element = element;
			NextNode->next = nullptr;
			temp = NextNode;
			map[index] = temp;
			delete NextNode;
			delete temp;
		}
		else {
			Linked* TempLinked = new Linked;
			TempLinked = map[index];
			while (TempLinked->next != nullptr) {
				TempLinked = TempLinked->next;
			}
			TempLinked->element = element;
			TempLinked->next = nullptr;
			map[index] = TempLinked;
			delete TempLinked;
		}

	}
	void print_table(Linked** map, int table_size) {
		for (int i = 0; i < table_size; i++) {
			Linked* temp_linked = map[i];
			while (temp_linked->next) {
				HT_Item* temp_item = new HT_Item;
				*temp_item = temp_linked->element;
				cout << "Key: " << temp_item->key << ' ';
				cout << "Value: " << temp_item->value << "->";
				temp_linked = temp_linked->next;
			}
			cout << endl;
		}
	}
}