#include <iostream>//подключение стадартной библиотеки
using namespace std;
void multiple(int n, ...);//прототип функции переменного кол-ва параметров
void main()//главная функция
{
	setlocale(LC_ALL, "Russian");
	//три варианта использования функции
	multiple(9, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	multiple(16, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	multiple(25, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25);
}

void multiple(int n, ...)//функция переменного кол-ва параметров
{
	int* pointer = &n;//указатель на первый элемент
	int amm_of_strings = sqrt(*pointer);//вычисление кол-ва строк квадратной матрицы
	int* arr_for_matrix = new int[n];
	//ввод элементов во вспомогательный массив
	for (int i = 0; i < n; i++) {
		*(arr_for_matrix + i) = *(++(++pointer));
	}
	int count_strings = 0;//создание счётной переменной
	for (int i = 0; i < n; i++) {//цикл для вывода элементов в виде квадратной матрицы
		if (count_strings % amm_of_strings == 0) {
			cout << endl;
		}
		cout << *(arr_for_matrix + i) << ' ';
		count_strings++;
	}
	cout << endl;//новая трока после вывода
	//создание счётный переменных необходимых для вычислений
	int sum_below_main = 0;
	int number_of_first = 1;
	int count_elements = 1;
	for (int i = 0; i < n; i++) {//цикл для подсчёта суммы элементов стоящих ниже главной диагонали матрицы
		int number_of_string = count_elements / amm_of_strings;//вычисление номера строки
		if (count_elements % amm_of_strings == 0) {//если есть переход на следующую строку
			number_of_first = number_of_first + amm_of_strings;//пристоить переменной номер первого элемента этой строки
		}
		if (number_of_string >= 1) {//если номер строки как минимум второй
			if (i >= number_of_first-1 && i < (number_of_first + number_of_string-1)) {//если элементы находятся в диапазоне от первого до последнего возможного для такой операции
				sum_below_main += *(arr_for_matrix + i);//прибавить значение элемента к сумме
			}
		}


		count_elements++;//подсчёт каждого элемента счётной переменной
	}
	cout<<"Сумма элементов ниже главной диагонали: " << sum_below_main << endl;//вывод ответа
}
