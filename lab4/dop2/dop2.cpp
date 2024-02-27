#include <iostream>//libraries
#include <fstream>
#include <string>
#define size 8//the size of an array
using namespace std;

struct TRAIN {//structure prototype
	string destination;
	int train_number;
	string departure_time;
};
int curr_size = 0;
struct TRAIN list_of_trains[size];//creating an array of structures
struct TRAIN sorted_trains[size];//creating an array for sorted 

//function prototypes
void enter_new();
void sort_array();
void train_nearby();

void main()//main function
{
	char choise;//creating a variable for switch-case operators
	do {
		//displaying the usage variants
		cout << "1-Enter new data" << endl;
		cout << "2-Check the nearest train" << endl;
		cout << "3-Check the sorted version" << endl;
		cout << "4-Clear the console" << endl;
		cout << "5-Exit" << endl;
		cin >> choise;
		cin.ignore();//clearing the buffer 
		while (!(choise >= '1' && choise <= '5')) {//checking if the choise variable is entered the right way
			cout << "Incorrect data!Try again: ";
			cin >> choise;
			cin.ignore();
		}
		int choise_sw = choise - '0';
		switch (choise_sw) {//variants of usage
		case 1:enter_new(); break;
		case 2:train_nearby(); break;
		case 3:sort_array(); break;
		case 4:system("cls"); break;
		}
	} while (choise!='5');//trace an exit variant
}

void enter_new()//function for entering the new information
{
	ofstream to_file("file.txt");//open file to write down
	cout << "Enter new train routes: " << endl;
	while (curr_size < size) {
		cout << "Rout number " << curr_size + 1 << " : " << endl;
		cout << "Enter the destination point: ";
		cin>>list_of_trains[curr_size].destination;
		to_file << list_of_trains[curr_size].destination << ' ';
		cin.ignore();//clearing the buffer
		cout << "Enter the number of a train: ";
		cin >> list_of_trains[curr_size].train_number;
		cout << "Enter the departure time (in 00:00 format): ";
		cin >> list_of_trains[curr_size].departure_time;
		to_file << list_of_trains[curr_size].departure_time << endl;
		cin.ignore();//clearing the buffer
		curr_size++;
	}
	to_file.close();//close file
	//sorting an array
	TRAIN temp;//creating a temporary structure
	for (int i = 0; i < size; i++) {//cycles for bouble sorting
		for (int j = 0; j < size; j++) {//bouble sorting
			if (list_of_trains[j].destination > list_of_trains[j+1].destination) {
				temp = list_of_trains[j];
				list_of_trains[j] = list_of_trains[j+1];
				list_of_trains[j+1] = temp;
			}
		}
	}
	cout << "All the information is entered!" << endl;
	cout << "What's next?" << endl;
}

void sort_array()//function for printing the sorted version of an array
{
	for (int i = 0; i < size; i++) {//cycle to print an array
		cout << "Train number " << list_of_trains[i].train_number << endl;
		cout << "Heading to " << list_of_trains[i].destination << endl;
		cout << "Departing at " << list_of_trains[i].departure_time << endl;
		cout << endl;
	}
}
void train_nearby()//function to see the nearest trains
{
	string departure_time;//getting the time 
	cout << "Enter the departure time to see nearest trains: ";
	getline(cin, departure_time);
	//checking if everything is entered the right way
	while (departure_time.length() < 5 || departure_time[2] != ':') {
		cout << "Incorrect format! Enter the time once again in 00:00 format: ";
		getline(cin, departure_time);
	}
	string hours;//getting hours in integer
	for (int i = 0; i < 2; i++) {
		hours += departure_time[i];
	}
	int hours_num = stoi(hours);

	string minutes;//getting minutes in integer
	for (int i = 3; i < 5; i++) {
		minutes += departure_time[i];
	}
	int minutes_num = stoi(minutes);
	//checking the trains
	bool check_near = false;//creating a variable to check is there any trains at all
	for (int i = 0; i < size; i++) {
		//getting the integer for hours of departure
		string check_hours;
		for (int j = 0; j < 2; j++) {
			check_hours += list_of_trains[i].departure_time[j];
		}
		int check_hours_num = stoi(check_hours);
		if (check_hours_num >= hours_num && check_hours_num <= hours_num + 1) {//check if there is a train within an hour
			check_near = true;//change the value of a logic variable
			//print all the info about the route
			cout << "There is a train departing at " << list_of_trains[i].departure_time << endl;
			cout << "The train is heading to " << list_of_trains[i].destination << endl;
			cout << "The train number is: " << list_of_trains[i].train_number << endl;
			cout << endl;
		}
	}
	//if there are no nearest trains
	if (check_near == false) {
		cout << "Unfortunately, there are no trains departing within at least 1 hour." << endl;
	}
	cout << "What's next?" << endl;

}