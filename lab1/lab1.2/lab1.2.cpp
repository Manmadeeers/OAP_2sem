#include <iostream>//подключение стандартной библиотеки
void multiple(int n, ...);//протитип функции с переменным кол-вом значений
using namespace std;
void main()//главная функция
{
	//три вызова функции переменного кол-ва параметров
	 multiple(6, -4, 5, 1, -2, 3, 10);
	 multiple(4, -1, 2, 3, -4);
	 multiple(5, 1, 10, -30, -40, 50);
}
void multiple(int n, ...)//функция переменного кол-ва параметров
{
	int* pointer = &n;//создвние указателя
	int* arr = new int[n];//выделение динамической памяти для  добавления чисел в массив
	for (int i = 0; i < n; i++) {//цикл для добавления в массив
		*(arr + i) = *(++(++pointer));
		cout << *(arr + i) << ' ';
	}
	cout << endl;
	//преобразование массива
	int count_negative = 0;//переменная для подсчётаотрицательных элементов
	for (int i = 0; i < n; i++) {//цикл для подсчёта
		if (*(arr + i) < 0) {
			count_negative++;
		}
	}
	int new_arr_size = n - count_negative;//размер массива , который будет хранить положительные элементы
	int* new_arr = new int[new_arr_size];//выделение динамической памяти под массив для положительных
	int* new_arr_neg = new int[count_negative];//выделение динамической памяти под массив отрицательных
	int for_neg = 0;//счётная переменная для массива отрицательных
	int for_new = 0;//счтная переменная для массива положительных
	for (int i = 0; i < n; i++) {//добавление положительных элементов в совй массив
		if (*(arr + i) >= 0) {
			*(new_arr + for_new) = *(arr + i);
			for_new++;
		}
		else {//добавление отрицательных элементов в свой массив
			*(new_arr_neg + for_neg) = *(arr + i);
			for_neg++;
		}
	}

	int* resulting_arr = new int[n];//выделение динамической памяти под итоговый массив
	for (int i = 0; i < for_new; i++) {//цикл для добавления сначала положительных элементов
		*(resulting_arr + i) = *(new_arr + i);
	}
	int helping_var = 0;//вспомогательная переменная для добавления отрицательных элементов
	for (int i = for_new; i < n; i++) {//цикл для добавления отрицательных
		*(new_arr_neg + helping_var) = 0;
		*(resulting_arr + i) = *(new_arr_neg + helping_var);
		helping_var++;
	}
	for (int i = 0; i < n; i++) {//вывод ответа
		cout << *(resulting_arr + i) << ' ';
	}
	cout << endl;

}