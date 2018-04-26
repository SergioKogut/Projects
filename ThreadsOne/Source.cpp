#include<iostream> 
#include<thread> //Файл в котором определен класс thread 
#include<string>
#include<chrono> 
using namespace std;

void Function(string NameThread) {
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
		
	thread func_thread(Function,"Tread 1"); // сворюємо потік
	this_thread::sleep_for(chrono::seconds(1));
	id = func_thread.get_id();
	cout << "ID Thread 1:"<<id<<endl;
	Function("Main Thread");
	if (func_thread.joinable())//
		func_thread.join(); //після виконання приєднуємо потік до основного
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