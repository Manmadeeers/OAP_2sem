#include "Header.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	string date;
	cout << "Введите дату в формате ДДММГГГГ: ";
	getline(cin, date);
	int length = date.length();
	string year_str;
	for (int i = length - 4; i < length; i++) {
		year_str += date[i];
	}
	int number_of_year = stoi(year_str);
	//tell if the year is leap or not
	if (check_if_leap(number_of_year) == true) {
		cout << "Этот год високосный" << endl;
	}
	else {
		cout<<
	}
}
