#include<iostream> 
#include<thread> //Файл в котором определен класс thread 
using namespace std;

void anyFunc() {
	cout << "thread function";
}

int main() {
	thread func_thread(anyFunc);
	func_thread.join();
	// Выполнение возвращается функции main когда поток заканчивается 
	return 0;
}