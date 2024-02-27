#include <iostream>//подключение стандартной библиотеки
using namespace std;
double equasion1(double);//прототип функции для первого уравнения
double equasion2(double);//прототип функции для второго уравнения
double dehotomie(double,double,double,double(*)(double));//прототип функции, реалтзующей метод дихотомии
void main() {//главная функция
	setlocale(LC_ALL, "Russian");
	double a, b, e = 0.001;
	cout << "а: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "Корень уравнения 1: " << dehotomie(a, b, e, equasion1)<<endl;//вычисления корня первого уравнения с использованием ссылки на функцию
	cout << "Корень уравнения 2: " << dehotomie(a, b, e, equasion2);//вычисление корня второго уравнения с использованием ссылки на функцию
}

double equasion1(double x)//функция для первого уравнения
{
	return(2 * x) + pow(x, 3) - 7;
}
double equasion2(double x)//функция для второго уравнения
{
	return exp(x) + (2 * x);
}
double dehotomie(double a, double b, double e, double(*func)(double))//функция для метода дихотомии
{
	double Answer;//переменная для ответа на урваниеия 
	while (abs(a - b)>(2*e)) {//цикл для метода дихотомии
		//метод дихотомии
		Answer = (a + b) / 2;
		if (func(Answer) * func(a) <= 0) {
			b = Answer;
		}
		else {
			a = Answer;
		}
	}
	return Answer;//вернуть корень уравнения
}


