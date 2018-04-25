#include<iostream>;

#include"stdafx.h";

using namespace std;


int x(int &a, int &b) 
{
	a = 3;
	b = 4;
	return a + b;
}

void main()
{

	int a = 2;
	int b = 7;
	int c = x(a, a);


	cout << a << b << c;



}