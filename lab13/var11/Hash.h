#pragma once
#define HASHDEL (void*) -1
struct Object
{
	void** data;
	Object(int, int(*)(void*));
	int size; int N;
	int(*getKey)(void*);
	bool insert(void*);
	int searchInd(int key);
	void* search(int key);
	void* deleteByKey(int key);
	bool deleteByValue(void*);
	void scan(void(*f)(void*));
	void resize(Object* obj, int oldSize, int newSize);
};
static void* DEL = (void*)HASHDEL;
Object create(int size, int(*getkey)(void*));
#undef HASHDEL