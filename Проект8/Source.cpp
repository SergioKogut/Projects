#include<iostream>;



using namespace std;


int x(int &a, int &b)
{
	a = 3;
	b = 4;
	return a + b;
}

void func(int x)
{
	if (x>0)
	{
		func(--x);
		cout << x;
	}
	else
	{
		return;
	}

}

template <class T>
T max(T x, T y, T z) {
	T m = x;
	if (y>m)
			m = y;
	
	if (z > m)
			m = z;
	
	return m;
}



void main()
{

	int a = 2;
	int b = 7;
	int c = x(a, a);
	
	cout << a << b << c << endl;

	func(5);

	cout << endl;
	cout << max('A', 'a', 'C') << endl;


	for (int a = 4; a < 8; a+=2)
	{
		cout << --a;
	}
}