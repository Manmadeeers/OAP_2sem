#include <iostream>
using namespace std;
//function prototypes
double equasion1(double);
double equasion2(double);
double dehotomie(double, double, double, double(*)(double));


void main()//main function
{
	setlocale(LC_ALL, "Russian");
	double a, b, e = 0.001;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "the answer to the first equasion is: " << dehotomie(a, b, e, equasion1) << endl;
	cout << "the answer to the second equasion is: " << dehotomie(a, b, e, equasion2);
}

double equasion1(double x)//function that returns first equasion
{
	return sin(x) + 2 + x;
}
double equasion2(double x)//function for the second equasion
{
	return 2 + pow(x, 3);
}
double dehotomie(double a, double b, double e, double(*func)(double))//function for the dehotomie method
{
	double answer;//переменная для ответа
	while (abs(a - b) > (2 * e)) {//цикл для реализации метода дихотомии
		//метод дихотомии
		answer = (a + b) / 2;
		if (func(answer) * func(a) <= 0) {
			b = answer;
		}
		else {
			a = answer;
		}
	}
	return answer;//вернуть корень уравнения

}