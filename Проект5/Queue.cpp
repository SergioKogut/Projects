#include<iostream>
#include"conio.h"

using namespace std;

template <typename T>
class tQueue
{
public:
	tQueue(int sizeQueue = 10) :
		size(sizeQueue),
		begin(0), end(0), CountElement(0)
	{
		// �������������� ������ ������� ��� ��������� ����� � ������ �������
		arr = new T[size + 1];
	}
	tQueue(const tQueue &obj) :
		size(obj.size), begin(obj.begin),
		end(obj.end), CountElement(obj.CountElement),
		arr(new T[size + 1])
	{
		for (int ix = 0; ix < size; ix++)
			arr[ix] = obj.arr[ix]; // �������� �������
	}
	
	void Push(const T &newElem)
	{
		// ���������, ���� �� ��������� ����� � �������
		if(CountElement < size)
		{
		// �������� �������� �� ��, ��� ������� �������� ����������� � 0 �������
		arr[end++] = newElem;

		CountElement++;
		
		// �������� ��������� ���������� �������
		if (end > size)
			end -= size + 1; // ���������� end �� ������ �������
		}
	}
	T Pop()
	{
		T returnValue;
		// ���������, ���� �� � ������� ��������
		if (CountElement > 0) {

			 returnValue = arr[begin++];
			CountElement--;
		
		// �������� ��������� ���������� �������
		if (begin > size)
			begin -= size + 1; // ���������� behin �� ������ �������
		}
		return returnValue;
	}
	void Print()
	{
		cout << "Queue: ";

		if (end == 0 && begin == 0)
			cout << " empty\n";
		else
		{
			for (int ix = end; ix >= begin; ix--)
				cout << arr[ix] << " ";
			cout << endl;
		}
	}

	~tQueue()
	{
		delete[] arr;
	}

private:
	T* arr;
	int begin;
	int end;
	int CountElement;

	const int size;

};








void main()
{
	int ElementCount;
	cout << "Enter count elements: " ;
	cin >> ElementCount;

	tQueue<char> myQueue(ElementCount); // ������ ������ �������

	myQueue.Print(); // ����� �������

	int ct = 1;
	char ch;

	// ���������� ��������� � �������
	

	cout << "Enter elements: " << endl;

	cin >> ch;


	while (ct++ < 5)
	{

		cin >> ch;
		myQueue.Push(ch);
	}

	myQueue.Print(); // ����� �������

						  // �������� �������� �� �������
	myQueue.Pop();
	myQueue.Pop();
	myQueue.Pop();

	myQueue.Print(); // ����� �������

	cout << "\n\n�������� ����������� �����������:\n";
	tQueue<char> newQueue(myQueue);

	newQueue.Print(); // ����� �������



	cout << "Hello!";

	

}
