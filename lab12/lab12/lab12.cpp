#include "Header.h"
#include <iostream>
using namespace std;
heap::CMP cmpAAA(void* a1, void* a2) //Функция сравнения
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice;
	heap::Heap h1 = heap::create(30, cmpAAA);//create a heap with 30 elements max and with a function of comparison
	for (;;)
	{
		cout << "1 - вывод кучи на экран" << endl;
		cout << "2 - добавить элемент" << endl;
		cout << "3 - удалить максимальный элемент" << endl;
		cout << "4 - Удаление минимального элемента" << endl;
		cout << "5 - Удалить i-й элемент" << endl;
		cout << "6 - Объеденить две кучи" << endl;
		cout << "7 - Найти элемент" << endl; 
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl; cin >> choice;
		switch (choice){ 
		case 0: exit(0);
		case 1: h1.scan(0);
			break;
		case 2: {
			AAA* a = new AAA;
			cout << "введите ключ" << endl; cin >> k;
			a->x = k;
			h1.insert(a);
		}
			  break;
		case 3: h1.extractMax();
			break;
		case 4:
			h1.extractMin();
			break;
		default: cout << endl << "Введена неверная команда!" << endl;
		}
	} return 0;
}