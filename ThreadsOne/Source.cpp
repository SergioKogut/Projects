#include<iostream> 
#include<thread> //Файл в котором определен класс thread 
#include<string>
#include<chrono> 
#include <Windows.h>

using namespace std;

void SetTextColor(int color, string text)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << text << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

}
void SetColorNumber(int color )
{
	
	for (int i = 0; i < 100; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		cout << " "<< i << " ";
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	}


}


void Function(string NameThread) {
	for (int i = 0; i < 100; i++)
	{
		SetTextColor(10, to_string(i));
	}
	
	cout << "Thread function: " << NameThread << endl;
}

class arrayModifier {
public:

	void operator()(int a[], int len) {
		for (int i = 0; i < len; i++) {
			a[i] *= 2;
		}
	}

	void invers(int a[], int len) {
		for (int i = 0; i < len; i++) {
			a[i] *= -1;
		}
	}
};


int main() 
{
	//-----------------------------------------------------------------------------------------------
	thread::id id;
	thread func_thread1(SetColorNumber,10); // сворюємо потік 1
	thread func_thread2(SetColorNumber, 11); // сворюємо потік 2

	 //this_thread::sleep_for(chrono::seconds(1));
	//id = func_thread.get_id();
	//cout << "ID Thread 1:"<<id<<endl;
	SetColorNumber(12);
	if (func_thread1.joinable())//
		func_thread1.join(); //після виконання приєднуємо потік до основного
	if (func_thread2.joinable())//
		func_thread2.join(); //після виконання приєднуємо потік до основного
	// Выполнение возвращается функции main когда поток заканчивается 
	// func_thread.detach(); В этом случае поток заканчивается принудительно 

	//-----------------------------------------------------------------------------------------------
	const int length = 5;
	int arr[length] = { 1, 2, 3, 4, 5 };
	arrayModifier obj;
	cout << "Output the array before threads\n";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ' ';
	}
	// Инициализируется объект функцией 
	thread arr_thread(obj, arr, length);
	// Инициализируется обычным открытым методом 
	thread arr_thread2(&arrayModifier::invers, &obj, arr, length);
	if (arr_thread.joinable()) arr_thread.join();
	if (arr_thread2.joinable()) arr_thread2.join();
	cout << "\nOutput th array after threads\n";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ' ';
	}

	//-----------------------------------------------------------------------------------------------








	return 0;
}