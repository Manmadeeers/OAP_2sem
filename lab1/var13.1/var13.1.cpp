#include <iostream>
using namespace std;
//прототипы для функций 1,2 и функции дихотомии
double equasion1(double);
double equasion2(double);
double dehotomie(double, double, double, double(*)(double));
void main()//главная функция
{
	setlocale(LC_ALL, "Russian");//локализаци консоли
	double a, b, e = 0.001;
	//ввод данных
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "Answer to equasion 1 is: " << dehotomie(a, b, e, equasion1) << endl;//вывод для уравнения 1
	cout << "Answer to equasion 2 is: " << dehotomie(a, b, e, equasion2);//вывод для уравнения 2

}
double equasion1(double x)//функция для первого уравнения
{
	return(5 * x) - 1 + pow(x, 3);
}
double equasion2(double x)//функция для второго уравнения
{
	return pow(x, 2) + (1 / x);
}
double dehotomie(double a, double b, double e, double(*func)(double))//функция для реализации метода дихотомии
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