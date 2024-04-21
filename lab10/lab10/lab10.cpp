#include <iostream>
using namespace std;

double cos_sum(int n,int x)//function to calculate cosinus
{
	if (n == 0) {//if the returning value is null
		return 0;
	}
	else {//if not
		return cos(n * x) + cos_sum(n-1, x);//recurtion
	}
}

void main()//main fucntion
{
	int x;//enter the angle
	cout << "Enter x for cosinus: ";
	cin >> x;
	int n;//enter the limit
	cout << "Enter the limit: ";
	cin >> n;
	double y = cos_sum(x, n);//use recurtion
	cout << "The required sum is: " << y << endl;
}