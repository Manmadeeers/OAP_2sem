#pragma once
struct AAA//structure to print an element of a binety heap
{
	int x;
	void print();
};
namespace heap//namespace to avoid naming conflicts while using a heap
{
	enum CMP//enum to optimize the comparison process
	{
		LESS = -1, EQUAL = 0, GREAT = 1
	};
	struct Heap//structure that defines a binary heap
	{
		int size;//size of a heap
		int maxSize;//maximal amount of elements in the heap
		void** storage; // data stored as a pointer to the dynamic data storge(void)
		CMP(*compare)(void*, void*);//comparison of to nodes from the storage using "compare" function
		Heap(int maxsize, CMP(*f)(void*, void*))//constructor of the Heap structure that defines a structure with a compare function  and a maximal size and allocates memory for storage
		{
			size = 0;//start to count the amount of elements in a heap
			storage = new void* [maxSize = maxsize];//memory allocation
			compare = f;//comparison
		};
		int left(int ix);//function to get an index of element in the left branch
		int right(int ix);//function to get an index of an element in the right branch
			int parent(int ix);//function to get an index of a certain parent
		bool isFull() const//function to check if the heap is full
		{
			return (size >= maxSize);
		};
		bool isEmpty() const//function to check if the heap is empty
		{
			return (size <= 0);
		};
		bool isLess(void* x1, void* x2) const//fucntion to check if  on of the elements from a storage is smaller than the other one using enum
		{
			return compare(x1, x2) == LESS;
		};
		bool isGreat(void* x1, void* x2) const//function to check uf one of the elements from a storage is greater than another one using enum
		{
			return compare(x1, x2) == GREAT;
		};
		bool isEqual(void* x1, void* x2) const//function to check if two elements from a storage are equal
		{
			return compare(x1, x2) == EQUAL;
		};
		void swap(int i, int j);//function that swaps two elements with each other
		void heapify(int ix);
		void insert(void* x);
		void* extractMax();//function that deletes the maximal element of a heap
		void* extractMin();//function to delete a minimal element of a heap
		void scan(int i) const;//function to scan the whole hip
		void* extractI(int i);//function tat extracts an element by index
		int find(int value);//function to find an element by value
		void increaseKey(int i, int newKey);//function to increase the chosen key
		void removeByValue(int value);//function that removes an element by value

	};
	Heap create(int maxsize, CMP(*f)(void*, void*));//constructor defined outside the namespace 
	Heap unionHeap(const Heap& h1, const Heap& h2);//function that unites two heaps
};