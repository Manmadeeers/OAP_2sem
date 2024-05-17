#include "Header.h"
#include <iostream>
#include <iomanip>
void AAA::print()//function that uses structure to print al element of a heap
{
	std::cout << x;
}
namespace heap//define functions in a namespace for a binary heap
{
	Heap create(int maxsize, CMP(*f)(void*, void*))//use constructor to create a new heap
	{
		return *(new Heap(maxsize, f));
	}
	int Heap::left(int ix)//calculate an index of a left chiled of a given element
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
	}
	int Heap::right(int ix)//calculate an index for a fight child of a given element
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
	}
	int Heap::parent(int ix)//calculate an index of a parent of a given element
	{
		return (ix + 1) / 2 - 1;
	}
	void Heap::swap(int i, int j)//bubble to swap two elements with given indeces with each other
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf;
	}
	void Heap::heapify(int ix)//restore an order of a heap after an element with a given index
	{
		int l = left(ix), r = right(ix), irl = ix;
		if (l > 0)
		{
			if (isGreat(storage[l], storage[ix])) irl = l;
			if (r > 0 && isGreat(storage[r], storage[irl])) irl = r;
			if (irl != ix)
			{
				swap(ix, irl);
				heapify(irl);
			}
		}
	}
	void Heap::insert(void* x)//function to insert a new element from a storage in a heap
	{
		int i;
		if (!isFull())
		{
			storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i]))
			{
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}
	void* Heap::extractMax()//deleting the maximal element of  a heap
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[0];
			storage[0] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}
	void* Heap::extractMin()
	{
		void* rc = nullptr;//указатель
		if (!isEmpty())
		{
			rc = storage[size - 1];
			storage[size - 1] = storage[0];
			size--;//уменьшаем размер
			heapify(size - 1);
		} return rc;
	}
	void* Heap::extractI(int i) {
		if (i < 0 || i >= size) {
			return nullptr; // Или выбросить исключение
		}
		void* rc = storage[i];
		// Перемещаем последний элемент в позицию i-ого
		storage[i] = storage[size - 1];
		size--;
		Heap::heapify(i);
		return rc;
	}
	Heap unionHeap(const Heap& h1, const Heap& h2) {
		// Создаем новую кучу с достаточным размером для хранения всех элементов из h1 и h2
		Heap newHeap = create(h1.maxSize + h2.maxSize, h1.compare);
		// Копируем элементы из h1 и h2 в newHeap
		for (int i = 0; i < h1.size; i++) {
			newHeap.insert(h1.storage[i]);
		}
		for (int i = 0; i < h2.size; i++) {
			newHeap.insert(h2.storage[i]);
		}
		return newHeap;
	}
	int Heap::find(int value) {
		for (int i = 0; i < size; i++) {
			if (((AAA*)storage[i])->x == value) {
				return i;
			}
		}
		return -1; // Элемент не найден
	}
	void Heap::increaseKey(int i, int newKey) {
		if (i < 0 || i >= size) {
			// Проверяем, что индекс находится в допустимом диапазоне
			return;
		}
		if (newKey < ((AAA*)storage[i])->x) {
			// Проверяем, что новый ключ больше текущего
			return;
		}
		((AAA*)storage[i])->x = newKey; // Обновляем ключ
		while (i > 0 && isLess(storage[parent(i)], storage[i])) {
			// Перемещаем элемент вверх по куче, пока он не будет на своем месте
			swap(parent(i), i);
			i = parent(i);
		}
	}
	void Heap::removeByValue(int value) {
		int index = find(value);
		if (index != -1) {
			// Если элемент найден, удаляем его
			extractI(index);
		}
	}



	void Heap::scan(int i) const //scan the whole heap and print all it's elements
	{
		int probel = 20;
		std::cout << '\n';
		if (size == 0)
			std::cout << "Куча пуста";
		for (int u = 0, y = 0; u < size; u++)
		{
			std::cout << std::setw(probel + 10) << std::setfill(' ');
			((AAA*)storage[u])->print();
			if (u == y)
			{
				std::cout << '\n';
				if (y == 0)
					y = 2;
				else
					y += y * 2;
			}
			probel /= 2;
		}
		std::cout << '\n';
	}
}