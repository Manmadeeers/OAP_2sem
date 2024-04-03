#include <iostream>
#include <fstream>//libraries
#include <string>

using namespace std;

ofstream g("g.txt");//open file to write down the result

struct MyNumbers//structure for a single linked list
{
    char number;
    MyNumbers* next;
};
//prototypes
void fromFile(MyNumbers*&, MyNumbers*&);
void pop(MyNumbers*&, MyNumbers*&, int);
void push(MyNumbers*&);

int main() {//main funciton
    MyNumbers* first = nullptr;//pointers to the first and the last element of queue
    MyNumbers* end = first;
    int choice;
    do
    {
        cout << "What to do? ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            fromFile(first, end);
            break;
        default:
            break;
        }
    } while (choice != 3);

    return 0;
}
void fromFile(MyNumbers*& first, MyNumbers*& end) {//extract elements from file
    ifstream f("f.txt");


    string baff;
    int gg = 0;

    while (getline(f, baff))
    {
        for (int i = 0; baff[i] != '\0'; i++) {
            if (baff[i] != '1' && baff[i] != '2' && baff[i] != '3' && baff[i] != '4' && baff[i] != '5' && baff[i] != '6' && baff[i] != '7' && baff[i] != '8' && baff[i] != '9' && baff[i] != '0') {
                g << baff[i];
            }
            else {
                pop(first, end, baff[i]);
                gg++;
            }
        }
        push(first);
        end = first;
        g << endl;
    }
    g.close();
    f.close();//close files 
}

void pop(MyNumbers*& begin, MyNumbers*& end, int value) {//fucntion to pop queue elements
    MyNumbers* p = new MyNumbers;
    if (end == NULL) {
        p->number = value;
        p->next = nullptr;
        begin = end = p;
        return;
    }
    p->next = NULL;
    if (begin == NULL) {
        begin = end = p;
    }
    else {
        p->number = value;
        end->next = p;
        end = p;
    }
}

void push(MyNumbers*& begin) {//function to push elements to queue
    MyNumbers* p = begin;
    if (p == NULL) {
        cout << "(((" << endl;
    }
    else {
        while (p != NULL) {
            g << p->number;
            p = p->next;
        }
    }
    delete[] begin;//delete the current pointer
    begin = nullptr;//set the pointer in the originall funciton as here
}