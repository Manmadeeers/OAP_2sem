#include "List.h"
#include <iostream>
using namespace std;
bool Object::Insert(void* data) // Вставка в начало
{
	bool rc = 0;
	if (Head == NULL)
	{
		Head = new Element(NULL, data, Head);
		rc = true;
	}
	else
	{
		Head = (Head->Prev = new Element(NULL, data, Head));
		rc = true;
	}
	return rc;
}
//-----------------------------------------------------------
Element* Object::Search(void* data) // Найти заданный элемент
{
	Element* rc = Head;
	while ((rc != NULL) && (rc->Data != data))
		rc = rc->Next;
	return rc;
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(void*)) // Вывод
{
	Element* e = Head;
	while (e != NULL)
	{
		f(e->Data);
		e = e->GetNext();
	};
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(void*), Element* e)
{
	f(e->Data);
}
//-----------------------------------------------------------
bool Object::Delete(Element* e) // Удалить по ссылке
{
	bool rc = 0;
	if (rc = (e != NULL))
	{
		if (e->Next != NULL)
			e->Next->Prev = e->Prev;
		if (e->Prev != NULL)
			e->Prev->Next = e->Next;
		else
			Head = e->Next;
		delete e;
	}
	return rc;
}
//-----------------------------------------------------------
bool Object::Delete(void* data) // Удалить по значению
{
	return Delete(Search(data));
};
//-----------------------------------------------------------
Element* Object::GetLast()
{
	Element* e = Head, * rc = e;
	while (e != NULL)
	{
		rc = e;
		e = e->GetNext();
	}
	return rc;
}
int Object::CountList() {
	Element* e = Head;
	int cnt = 0;
	while (e != NULL)
	{
		cnt++;
		e = e->GetNext();
	}
	Head = nullptr;
	return cnt;
}
//-----------------------------------------------------------
bool Object::DeleteList(int size) {
	Element* e = Head;
	for (int i = 0; i < size; i++) {
		bool rc = 0;
		if (rc = (e != NULL))
		{
			if (e->Next != NULL)
				e->Next->Prev = e->Prev;
			if (e->Prev != NULL)
				e->Prev->Next = e->Next;
			else
				Head = e->Next;
			delete e;
		}
	}
	return true;
}
//-----------------------------------------------------------
Object Create()
{
	return *(new Object());
}
struct Person
{
	string name;
	string capital;
	int amm_of_people;
	double square;
	string president_surename;
	Person* next;
};

void print(void* b) //Функция используется при выводе
{
	Person* a = (Person*)b;
	cout << a->name << " " << a->capital <<a->amm_of_people<<a->square<<a->president_surename<< endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Person a1 = { "Belarus","Minsk",9000000,10000,"Lukashenko"};
	Person a2 = { "Russia","Moscow",162000000,1000000,"Putin"};
	Person a3 = { "Poland","Warsaw",20000000,1000,"Duda"};
	bool rc;
	Object L1 = Create(); // создание списка с именем L1
	L1.Insert(&a1);
	L1.Insert(&a2);
	L1.Insert(&a3);
	L1.PrintList(print);
	Element* e = L1.Search(&a3);
	Person* aa = (Person*)e->Data;
	cout << "Найден элемент= " << aa->name << endl;
	rc = L1.Delete(&a2);
	if (rc == true) cout << "Удален элемент" << endl;
	cout << "Список:" << endl;
	L1.PrintList(print);
	cout << "amount of elements: " << L1.CountList() << endl;
	int size = L1.CountList();
	L1.DeleteList(size);
	cout << "The list is sucsessfully deleted" << endl;
	cout << "List: " << endl;
	L1.PrintList(print);
	return 0;
}