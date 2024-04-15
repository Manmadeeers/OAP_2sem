#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct DATA {
	string surename;
	string name;
	string patronimic;
	int b_year;
	int course;
	int grup_num;
	string marks;
	DATA* prev;
	DATA* next;
};

//prototypes
void insert(int size, DATA** head);
void print_data(DATA* head);
void sort_course(DATA* head);
void find_oldest_and_youngest(DATA* head);
void find_average(DATA* head);

void main()//main function
{
	DATA* head = nullptr;
	char choise;
	do {
		cout << "1-Enter data" << endl;
		cout << "2-Print data" << endl;
		cout << "3-Average point" << endl;
		cout << "4-Oldest and youngest" << endl;
		cout << "5-Clear" << endl;
		cout << "6-Exit" << endl;
		cin >> choise;
		//check input
		while (!(choise >= '1' && choise <= '6')) {
			cout << "invalid input!Try again: ";
			cin >> choise;
		}
		int choise_sw = choise - '0';//convert char to int
		int size;
		switch (choise_sw) {
		case 1:
			cout << "How many students would you like to insert: ";
			cin >> size;
			insert(size, &head);
			break;
		case 2:
			sort_course(head);
			print_data(head); break;
		case 3:find_average(head); break;
		case 4:find_oldest_and_youngest(head); break;
		case 5:system("cls"); break;
		}
		

		
	} while (choise!='6');
}

void insert(int size, DATA** head)//function toinsert the required amount of new info
{
	for (int i = 0; i < size; i++) {
		cout << "Student number " << i << " :" << endl;
		DATA* NewNode = new DATA();//memory for a new node
		string str_tmp;
		cin.ignore(cin.rdbuf()->in_avail());//clear buffer
		//get info for node
		cout << "Enter surename: ";
		getline(cin, str_tmp);
		NewNode->surename = str_tmp;
		cout << "Enter name: ";
		getline(cin, str_tmp);
		NewNode->name = str_tmp;
		cout << "Enter patronimic: ";
		getline(cin, str_tmp);
		NewNode->patronimic = str_tmp;
		int int_tmp;
		cout << "Enter the year of birth: ";
		cin >> int_tmp;
		NewNode->b_year = int_tmp;
		cout << "Enter course: ";
		cin >> int_tmp;
		NewNode->course = int_tmp;
		cout << "Enter group: ";
		cin >> int_tmp;
		NewNode->grup_num = int_tmp;
		char temp_mark;
		string temp_mark_str;
		for (int i = 0; i < 5; i++) {//cycle to enter all the marks
			cout << "Enter mark:";
			cin >> temp_mark;
			temp_mark_str += temp_mark;
			if (i != 4) {
				temp_mark_str += ';';
			}
		}
		//insert node into the original list
		NewNode->marks = temp_mark_str;
		NewNode->next = (*head);
		NewNode->prev = nullptr;
		if ((*head) != nullptr)
			(*head)->prev = NewNode;
		(*head) = NewNode;
		system("cls");
	}
	
}
void sort_course(DATA* head)//fucntion to sort list by course
{
	bool swaped;
	DATA* ptr;
	DATA* lptr = nullptr;
	if (head == nullptr) {
		return;
	}
	//bubble sort
	do {
		swaped = false;
		ptr = head;
		while (ptr->next != nullptr) {
			if (ptr->course > ptr->next->course) {
				swap(ptr, ptr->next);
				swaped = true;
			}
			ptr = ptr->next;
		}
	} while (swaped);
}
void find_oldest_and_youngest(DATA* head)//function to find the oldest student
{
	DATA* old_ptr = head;
	int oldest = old_ptr->b_year;
	while (old_ptr != nullptr) {
		if (old_ptr->b_year < oldest) {
			oldest = old_ptr->b_year;
		}
		old_ptr = old_ptr->next;
	}
	cout << "The oldest student was born in year " << oldest << endl;
	DATA* young_ptr = head;
	int youngest = young_ptr->b_year;
	while (young_ptr != nullptr) {
		if (young_ptr->b_year > youngest) {
			youngest = young_ptr->b_year;
		}
		young_ptr = young_ptr->next;
	}
	cout << "The youngest student was born in year " << youngest << endl;

}
void find_average(DATA* head)//funciton to find the average point 
{
	DATA* ptr = head;
	int size = 0;
	while (ptr != nullptr) {//calculate the list size
		size++;
		ptr = ptr->next;
	}
	float whole_marks = size * 5;
	ptr = head;//set pointer to the start
	float sum = 0;
	while (ptr != nullptr) {//summ all the marks
		string temp = ptr->marks;
		int temp_length = temp.length();
		for (int i = 0; i < temp_length; i++) {//summ up all the marks
			if (temp[i] != ';') {
				sum += temp[i] - '0';
			}
		}
		ptr = ptr->next;
	}
	//calculte the average
	float average = sum / whole_marks;
	cout << "The avarage mark is: " << average << endl;
}

void print_data(DATA* head)//function to print data from a list
{
	system("cls");
	while (head != nullptr) {
		cout << "Surename: " << head->surename << endl;
		cout << "Name: " << head->name << endl;
		cout << "Patronimic: " << head->patronimic << endl;
		cout << "Year of birth: " << head->b_year << endl;
		cout << "Course: " << head->course << endl;
		cout << "Group number: " << head->grup_num << endl;
		cout << "Marks: " << head->marks << endl;
		head = head->next;
	}
	cout << endl << endl;
}	