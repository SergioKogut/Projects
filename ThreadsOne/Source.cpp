#include<iostream> 
#include<thread> //���� � ������� ��������� ����� thread 
using namespace std;

void anyFunc() {
	cout << "thread function";
}

int main() {
	thread func_thread(anyFunc);
	func_thread.join();
	// ���������� ������������ ������� main ����� ����� ������������� 
	return 0;
}