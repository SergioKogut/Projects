#include<iostream>
#include"conio.h"
#include <Windows.h>


using namespace std;

template <class T>
class tStack
{
	
public:
	tStack(int size = 100) :MaxLen(size)
	{
		arr = new T[size]; Top = EMPTY;
	};
	~tStack(){
	  delete []arr;
	}
	void reset() { Top = EMPTY;}
	void push(T obj) { arr[++top] = omj;}
	T pop() { return arr[top--]; }
	T top_of() { return arr[Top];}
	bool empty() { return (Top == EMPTY);}
	boll full() { return (Top == MaxLen - 1); }
	
private:
	enum { EMPTY = -1 };
	T* arr; // вказівник на масив 
	int  MaxLen; // максимальна довжина
	int Top; // верх стеку
	
};



int main()
{

	cout << "Hello!" << endl;
	_getch();

	return 0;
}