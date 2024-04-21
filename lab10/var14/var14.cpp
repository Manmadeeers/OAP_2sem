#include <iostream>
using namespace std;
long long factorial(int n)//function to count factorial
{
	if (n == 0 || n == 1) {//if n is 0 or 1
		return 1;
	}
	else {//if not
		return n * factorial(n - 1);
	}
}
double calculate(double x, double n)//function to use recursion
{
	if (n == 0) {
		return 0;
	}
	else {
		return (pow(x, n) / factorial(n)) + calculate(n - 1, x);//the use of recursion itself
	}
}

void main()//main function
{
	double x;
	cout << "Enter x: ";
	cin >> x;
	double n;
	cout << "Enter n:";
	cin >> n;
	double result = calculate(x, n);//calculate 
	cout << "The result is: " << result << endl;
}