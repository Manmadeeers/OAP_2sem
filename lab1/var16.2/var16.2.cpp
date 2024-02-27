#include <iostream>//подключение стадратной библиотеки
using namespace std;
//function prototype
void mult(int n, ...);//прототип функции

void main()//главная функция
{
	setlocale(LC_ALL, "Russian");//локализация консоли
	//три варианта использования функции 
	mult(2, 1, 10);
	mult(2, 1, 5);
	mult(2, 1, 20);
}

void mult(int n, ...)//функция переменного кол-ва параметров
{
	int* pointer = &n;//указатель
	int* arr_for_range = new int[n];//массив для получения промежутка
	cout << "Интервал: ";
	for (int i = 0; i < n; i++) {//цикл для записи элементов в массив и их вывода
		*(arr_for_range + i) = *(++(++pointer));
		cout << *(arr_for_range + i)<<' ';
	}
	cout << endl;
	int start = arr_for_range[0];//переменная, которая хранит начало отсчёта
	int end = arr_for_range[n-1];//перемменная , которая хранит конец отсчёта
	cout << "Числа в интервале: ";
	int* arr_to_check = new int[end];//массив для всех чисел в интервале
	int count_var = 0;//счётная переменная для массива
	int count_numbers;//счётная переменная для цикла проверки 
	for (int i = start; i <= end; i++) {//цикл для вывода всех чисел из интревала
		arr_to_check[count_var] = i;
		cout << arr_to_check[count_var]<<' ';
		count_var++;
		count_numbers = count_var;
	}
	cout << endl;
	//проверка на простые числа
	for (int i = 0; i <count_numbers; i++) {//цикл для проверки , является ли число простым
		for (int j = 1; j <= arr_to_check[i] / 2; j++) {
			if (arr_to_check[i] < 1) {
				i++;
			}
			if (arr_to_check[i] % j == 0) {
				if (i == count_numbers - 1) {
					break;
				}
				i++;

			}
			cout << arr_to_check[i] << "-простое число  ;";//вывод простых чисел
			break;
		}
	}
	cout << endl;

}