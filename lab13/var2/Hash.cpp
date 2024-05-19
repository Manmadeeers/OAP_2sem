#include "Hash.h"
#include <iostream>
#include <cstdlib>
struct HashFunctionWrapper {//structure to store functions to reslize universal hashing
	int (*func)(int, int, int);//pointers to functions
};
int simpleHash(int key, int size, int p) {//function for simple hashing
	return (key + p) % size;
}

int complexHash(int key, int size, int p) {//function for complex hashing
	double key2 = 5 * ((0.6180339887499 * key) - int((0.6180339887499 * key)));
	return (p + key) % size;
}

int anotherComplexHash(int key, int size, int p) {//another function for complex hashing
	double key2 = 5 * ((0.6180339887499 * key) - int((0.6180339887499 * key)));
	return (p + key) % size; //mod operation
}

int HashFunction(int key, int size, int p) // hash function
{
	// Массив функций хеширования
	HashFunctionWrapper functions[] = {
		{simpleHash},
		{complexHash},
		{anotherComplexHash}
	};

	// get a random hash function
	int functionIndex = rand() % sizeof(functions) / sizeof(HashFunctionWrapper);
	int final_hash;//variable for a final hash value
	if (functionIndex == 0) {
		final_hash = simpleHash(key, size, p);
	}
	else if (functionIndex == 1) {
		final_hash = complexHash(key, size, p);
	}
	else if (functionIndex == 2) {
		final_hash = anotherComplexHash(key, size, p);
	}
	return final_hash;
}

//-------------------------------
int Next_hash(int hash, int size, int p)//calculating the variable for the next hash
{
	return (hash + 5 * p + 3 * p * p) % size;
}
//-------------------------------
Object create(int size, int(*getkey)(void*))//create a new hash-table
{
	return *(new Object(size, getkey));
}
//-------------------------------
Object::Object(int size, int(*getkey)(void*))//object function that  implements an object
{
	N = 0;
	this->size = size;
	this->getKey = getkey;
	this->data = new void* [size];
	for (int i = 0; i < size; ++i)
		data[i] = NULL;
}
//-------------------------------
bool Object::insert(void* d)//function that inserts an element into a hash table
{
	bool b = false;//variable to check if the table is full or not
	if (N != size)
		for (int i = 0, t = getKey(d), j = HashFunction(t, size, 0);
			i != size && !b; j = Next_hash(j, size, ++i))
			if (data[j] == NULL || data[j] == DEL)
			{
				data[j] = d;
				N++;
				b = true;
			}
	return b;
}
//-------------------------------
int Object::searchInd(int key)//function to search by index
{
	int t = -1;
	bool b = false;
	if (N != 0)
		for (int i = 0, j = HashFunction(key, size, 0); data[j] != NULL && i//cycle to search
			!= size && !b; j = HashFunction(key, size, ++i))
			if (data[j] != DEL)if (getKey(data[j]) == key)
			{
				t = j; b = true;
			}
	return t;
}
//-------------------------------
void* Object::search(int key)//the actual search function of a class
{
	int t = searchInd(key);
	return(t >= 0) ? (data[t]) : (NULL);
}
//-------------------------------
void* Object::deleteByKey(int key)//deletion by key
{
	int i = searchInd(key);
	void* t = data[i];
	if (t != NULL)//check to delete
	{
		data[i] = DEL;
		N--;
	}
	return t;
}
//-------------------------------
bool Object::deleteByValue(void* d)//deletion by value
{
	return(deleteByKey(getKey(d)) != NULL);
}
//-------------------------------
void Object::scan(void(*f)(void*))//scaning the whole table to print it
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << " Элемент" << i;
		if ((this->data)[i] == NULL)
			std::cout << " пусто" << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << " удален" << std::endl;
			else
				f((this->data)[i]);
	}
}