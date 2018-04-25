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
		// дополнительная позици поможет нам различать конец и начало очереди
		arr = new T[size + 1];
	}
	tQueue(const tQueue &obj) :
		size(obj.size), begin(obj.begin),
		end(obj.end), CountElement(obj.CountElement),
		arr(new T[size + 1])
	{
		for (int ix = 0; ix < size; ix++)
			arr[ix] = obj.arr[ix]; // копируем очередь
	}
	
	void Push(const T &newElem)
	{
		// проверяем, ести ли свободное место в очереди
		if(CountElement < size)
		{
		// обратите внимание на то, что очередь начинает заполняться с 0 индекса
		arr[end++] = newElem;

		CountElement++;
		
		// проверка кругового заполнения очереди
		if (end > size)
			end -= size + 1; // возвращаем end на начало очереди
		}
	}
	T Pop()
	{
		T returnValue;
		// проверяем, есть ли в очереди элементы
		if (CountElement > 0) {

			 returnValue = arr[begin++];
			CountElement--;
		
		// проверка кругового заполнения очереди
		if (begin > size)
			begin -= size + 1; // возвращаем behin на начало очереди
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

	tQueue<char> myQueue(ElementCount); // объект класса очередь

	myQueue.Print(); // вывод очереди

	int ct = 1;
	char ch;

	// добавление элементов в очередь
	

	cout << "Enter elements: " << endl;

	cin >> ch;


	while (ct++ < 5)
	{

		cin >> ch;
		myQueue.Push(ch);
	}

	myQueue.Print(); // вывод очереди

						  // удаление элемента из очереди
	myQueue.Pop();
	myQueue.Pop();
	myQueue.Pop();

	myQueue.Print(); // вывод очереди

	cout << "\n\nСработал конструктор копирования:\n";
	tQueue<char> newQueue(myQueue);

	newQueue.Print(); // вывод очереди



	cout << "Hello!";

	

}
