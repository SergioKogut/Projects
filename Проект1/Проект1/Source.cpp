#include<iostream>
#include <locale>
#include <math.h>
#include<conio.h>
#include<ctime>
using namespace std;

void  Mod(int *pDigit);					  // �������, ��� ������ �������� �� ����� � ������ � �� ������ ���� ����
void  Replace(int* pDigit1, int* pDigit2);//�������, ��� ���� �������� ��� ��������� � ����� �� �������� �����, �� �� ���� ��������.

int main()
{
	setlocale(LC_ALL, "Russian");

	/* ������ 1. ���� ��� �����. ��������� ��������� �� �� �����.
	�������� ������� ����� ������� �����, ������ �����������,
	�������� � ���, ������������ �������� �������� ��  ����� ����� ���������.*/
	/*2. �������� �������, ��� ������ �������� �� ����� � ������ � �� ������ ���� ����.
	3. �������� �������, ��� ���� �������� ��� ��������� � ����� �� �������� �����, �� �� ���� ��������.
	4. �������� �������, �� ������ ��� ���������, ��� ���� �������� ���� ���� ������ ����������� � �����.
	*/

	int P, Sr, min;
	int a = -5, b = 6, c = 9;
	int *ptra = &a;
	int *ptrb = &b;
	int *ptrc = &c;
	cin >> a;
	cout << "��i��� �:" << *ptra << "   ������  ��i��� �:" << ptra << endl;
	cout << "��i��� b:" << *ptrb << "   ������  ��i��� b:" << ptrb << endl;
	cout << "��i��� c:" << *ptrb << "   ������  ��i��� c:" << ptrc << endl << endl;
	P = *ptra**ptrb**ptrc;
	cout << "������� ��i���� a,b,c : " << P << endl;
	Sr = (*ptra + *ptrb + *ptrc) / 3;
	cout << "������ ����������� ��i���� a,b,c : " << Sr << endl;

	//2. �������� �������, ��� ������ �������� �� ����� � ������ � �� ������ ���� ����.

	Mod(ptra);
	cout << "������ ��i��� � : " << *ptra << endl;

	Replace(ptrb, ptrc);
	cout << "��i��� b:" << *ptrb << "   ������  ��i��� b:" << ptrb << endl;
	cout << "��i��� c:" << *ptrb << "   ������  ��i��� c:" << ptrc << endl << endl;
	
	
	
	
	_getch();
	return 0;
	
}






// �������, ��� ������ �������� �� ����� � ������ � �� ������ ���� ����
void  Mod(int *pDigit)
{
	*pDigit = abs(*pDigit);
}

// �������, ��� ���� �������� ��� ��������� � ����� �� �������� �����, �� �� ���� ��������
void  Replace(int* pDigit1, int* pDigit2)
{
	int *temp = pDigit1;
	pDigit1 = pDigit2;
	pDigit2 = temp;
}