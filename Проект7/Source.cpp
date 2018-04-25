#include <iostream>
#include <vector>
#include <iterator>
#include <time.h> //случайные числа
#include <stdio.h> //для printf
#include <windows.h> // для HANDLE, курсора, цвета
#include <conio.h>  //для kbhit
//#include <WinUser.h>  
using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

int stepp = 0;
int nn = 3; // кількість дисків ханнойської башти
int xnn = 3; // для пропуска трьох строчок
int d = nn - xnn;// мінімізування пропусків перед нумерацією

const int dn = 3;  // кількість дисків ханнойської башти 
int mass[dn][3] = { 1,0,0,2,0,0,3,0,0 };
//int* pmass = &mass[dn][3];
//mass[0][0] = 1;
//mass[1][0] = 2;
//mass[2][0] = 3;

void GotoXY(SHORT X, SHORT Y)
{
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}

void stolb1(int xx, int yy, int pov, int bokk)
{

	for (int bok = 0, nnn = 0; bok < bokk; nnn++, bok++)
	{
		// vpravo znak 1
		for (int i = 0, nnn = 0; i < nn; nnn++, i++)
		{
			GotoXY(xx + (nn)+(bok + 1), yy + xnn + (pov - 1)); cout << "-" << endl;

		}

		// vlevovo znak 1
		for (int i = 0, nnn = 0; i < nn; nnn++, i++)
		{
			GotoXY(xx + (nn)-(bok + 1), yy + xnn + (pov - 1)); cout << "-" << endl;

		}

	}

}

void stolb2(int xx, int yy, int pov, int bokk)
{

	for (int bok = 0, nnn = 0; bok < bokk; nnn++, bok++)
	{
		// vpravo znak 1
		for (int i = 0, nnn = 0; i < nn; nnn++, i++)
		{
			GotoXY(xx + (nn + 2 * (nn + 1)) + (bok + 1), yy + xnn + (pov - 1)); cout << "-" << endl;
		}

		// vlevovo znak 1
		for (int i = 0, nnn = 0; i < nn; nnn++, i++)
		{
			GotoXY(xx + (nn + 2 * (nn + 1)) - (bok + 1), yy + xnn + (pov - 1)); cout << "-" << endl;
		}

	}

}

void stolb3(int xx, int yy, int pov, int bokk)
{

	for (int bok = 0, nnn = 0; bok < bokk; nnn++, bok++)
	{
		// vpravo znak 1
		for (int i = 0, nnn = 0; i < nn; nnn++, i++)
		{
			GotoXY(xx + (nn + 2 * 2 * (nn + 1)) + (bok + 1), yy + xnn + (pov - 1)); cout << "-" << endl;
		}

		// vlevovo znak 1
		for (int i = 0, nnn = 0; i < nn; nnn++, i++)
		{
			GotoXY(xx + (nn + 2 * 2 * (nn + 1)) - (bok + 1), yy + xnn + (pov - 1)); cout << "-" << endl;
		}

	}

}

int init(int pmass[][3], int n, int src, int dest)
{
	for (int i = 0; i < nn; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (pmass[i][src] == n) // поиск по ключу
			{
				int ix = i;
				int temp = pmass[ix][src];
				//for (int k = 0; k <= nn; k++)
				//{
				pmass[nn - 0][dest - 1] = temp;
				pmass[ix][src] = 0;
				//}
			}
			//return (&mass[i][j]);             // позиция искомого элемента
		}
		//cout << endl;
	}


	return pmass[nn][3];
}

void XAN(int n, int src, int dest, int tmp, int xx, int yy, int stepp)
{
	int pov = 3;
	int bokk = 3;

	/*int mass[3][4] = {0};
	for (int i = 0; i < 3; i++)
	{
	for (int j = 0; j < 4; j++)
	{
	cout << mass[i][j] << " " << endl;
	}
	cout << endl;
	}*/

	/*GotoXY(20, 0);
	GotoXY(64, 2); cout << "Danue:" << endl;
	GotoXY(64, 3); cout << "Jablok:0" << endl;*/

	GotoXY(xx, yy);
	cout << stepp << " ) " << "Снимаем " << n << "-й диск с " << src << "-го стержня и одеваем его на " << dest << "-й стержень\n";
	cout << "Start!" << endl;
	/*const int dn = 3;
	int mass[dn][3] = { 0 };*/

	//int xn = n;
	//for (int i = 0; i < 3 ; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		if (mass[i][src] == xn) // поиск по ключу
	//		{
	//			int ix = i;
	//			int temp = mass[ix][src];
	//			//for (int k = 0; k <= nn; k++)
	//			//{
	//			mass[nn - 0][dest - 1] = temp;
	//			mass[ix][src] = 0;
	//			//}
	//		}
	//		mass[3][2] = 2;
	//	}
	//	//cout << endl;
	//}

	mass[nn][3] = init(&*mass, n, src, dest);
	init(&*mass, n, src, dest);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			/*stolb1(xx, yy, mass[i][0], mass[i][0]);
			stolb2(xx, yy, mass[i][1], mass[i][1]);
			stolb3(xx, yy, mass[i][2], mass[i][2]);*/

			/*stolb1(xx, yy, mass[i][j], mass[i][j]);
			stolb2(xx, yy, mass[i][j], mass[i][j]);
			stolb3(xx, yy, mass[i][j], mass[i][j]);*/

			/*for (int j = 0; j < 3; j++)
			{
			stolb1(xx, yy, mass[i][j], mass[i][j]);
			}
			for (int j = 0; j < 3; j++)
			{
			stolb2(xx, yy, mass[i][j], mass[i][j]);
			}
			for (int j = 0; j < 3; j++)
			{
			stolb3(xx, yy, mass[i][j], mass[i][j]);
			}*/

			//int k1 = mass[i][0];
			//for (int k = 0; k < 3; k++)
			//{
			stolb1(xx, yy, i + 1, mass[i][0]); // 1 2 3-poverx 4-disks
											   //}
											   //int k2 = mass[i][1];
											   //for (int k = 0; k < 3; k++)
											   //{
			stolb2(xx, yy, i + 1, mass[i][1]); // 1 2 3-poverx 4-disks
											   //}
											   //int k3 = mass[i][2];
											   //for (int k = 0; k < 3; k++)
											   //{
			stolb3(xx, yy, i + 1, mass[i][2]); // 1 2 3-poverx 4-disks
											   //	}

											   /*for (int k = 0; k < 2; k++)
											   {
											   stolb1(xx, yy, k + 1, k + 1);
											   }
											   for (int k = 0; k < 2; k++)
											   {
											   stolb2(xx, yy, k + 1, k + 1);
											   }
											   for (int k = 0; k < 2; k++)
											   {
											   stolb3(xx, yy, k + 1, k + 1);
											   }*/
			cout << endl;
		}
	}

	/*//baza rozraxynkiv
	for (int bok = 0, nnn = 0; bok < bokk; nnn++, bok++)
	{
	// vpravo znak 1
	for (int i = 0, nnn = 0; i < nn; nnn++, i++)
	{
	GotoXY(xx + (nn) + (bok + 1), yy + xnn + (pov - 1)); cout << "-" << endl;
	GotoXY(xx + (nn + 2 * (nn + 1)) + (bok + 1), yy + xnn + (pov - 1)); cout << "-" << endl;
	GotoXY(xx + (nn + 2 * 2 * (nn + 1)) + (bok + 1), yy + xnn + (pov - 1)); cout << "-" << endl;
	}

	// vlevovo znak 1
	for (int i = 0, nnn = 0; i < nn; nnn++, i++)
	{
	GotoXY(xx + (nn) -(bok + 1), yy + xnn + (pov - 1)); cout << "-" << endl;
	GotoXY(xx + (nn + 2 * (nn + 1)) - (bok + 1), yy + xnn + (pov - 1)); cout << "-" << endl;
	GotoXY(xx + (nn + 2 * 2 * (nn + 1)) - (bok + 1), yy + xnn + (pov - 1)); cout << "-" << endl;
	}

	}
	*/

	for (int i = 0, nnn = 0; i < nn; nnn++, i++)
	{
		GotoXY(xx + (nn), yy + xnn + nnn); cout << "|" << endl;
		GotoXY(xx + (nn + 2 * (nn + 1)), yy + xnn + nnn); cout << "|" << endl;
		GotoXY(xx + (nn + 2 * 2 * (nn + 1)), yy + xnn + nnn); cout << "|" << endl;
	}
	cout << endl;
	for (int i = nn; i < nn + 1; i++)
	{
		GotoXY(xx + (nn), yy + 2 * nn - d + 1); cout << "1" << endl;
		GotoXY(xx + (nn + 2 * (nn + 1)), yy + 2 * nn - d + 1); cout << "2" << endl;
		GotoXY(xx + (nn + 2 * 2 * (nn + 1)), yy + 2 * nn - d + 1); cout << "3" << endl;
	}
	cout << endl;

}

void GotoInsert(int n, int src, int dest, int tmp, int stepp)
{
	CONSOLE_SCREEN_BUFFER_INFO bi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bi);
	GotoXY(bi.dwCursorPosition.X, bi.dwCursorPosition.Y);
	XAN(n, src, dest, tmp, bi.dwCursorPosition.X, bi.dwCursorPosition.Y, stepp);
	//cout << "Start!" << endl;
}



void STENA()
{
	//SetColor(LightBlue, Black); 
	//GotoXY(20, 0);
	GotoXY(74, 2); cout << "Danue:" << endl;
	GotoXY(74, 3); cout << "Jablok:0" << endl;
	GotoXY(74, 4); cout << "Dlina:3" << endl;
	GotoXY(74, 5); cout << "Speed:0" << endl;
	GotoXY(74, 7); cout << "Uprawlenie:" << endl;
	GotoXY(74, 8); cout << "Esc:Wuxod" << endl;
	GotoXY(74, 9); cout << "P:Pause" << endl;
	GotoXY(74, 10); cout << "S:Start" << endl;
	GotoXY(74, 11); cout << "L:Level" << endl;

	//SetColor(LightMagenta, Black);
	/*GotoXY(2, 2);
	int m = 0;
	for (m = 0; m < 20; m++)
	{
	printf("*");
	}

	{
	GotoXY(2, 20);
	for (m = 0; m < 20; m++)
	{
	printf("*");
	}
	}
	{
	for (m = 2; m < 20; m++)
	{
	GotoXY(2, m);
	printf("*");
	}
	}
	{
	for (m = 2; m < 21; m++)
	{
	GotoXY(22, m);
	printf("*");
	}
	}*/
}


class State
{
	int n;
	int src;
	int dest;
	int tmp;

	friend void Towers(int n, int src, int dest, int tmp);

public:

	State()
	{

	}
	~State()
	{

	}

};


void Towers(int n, int src, int dest, int tmp)
{

	SetConsoleOutputCP(1251);
	if (n != 0)
	{
		Towers(n - 1, src, tmp, dest);

		++stepp;
		//cout << stepp  << " ) " << "Снимаем " << n << "-й диск с " << src << "-го стержня и одеваем его на " << dest << "-й стержень\n";

		GotoInsert(n, src, dest, tmp, stepp);

		Towers(n - 1, tmp, dest, src);
	}
}



void main()
{

	GotoXY(7, 0);
	cout << "Start!" << endl;

	cout << "Hannoy Touwer : " << endl << endl;
	cout << "  -|-      |       |" << endl;
	cout << " --|--     |       |" << endl;
	cout << "---|---    |       |" << endl << endl;
	cout << "   1       2       3" << endl;
	cout << endl;

	Towers(nn, 1, 3, 2);

	//STENA();

	//const int dn = 3;
	//int mass[dn][4] = { 2 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//mass[i][j] = 2;
			//mass[i][0] = i + 1;
			cout << mass[i][j] << " ";
		}
		cout << endl;
	}


	//// уничтожение
	//for (int i = 0; i < nn; i++) {
	//	delete[] mass[i];
	//}
	//delete[] mass;

	_getche();
	system("pause");
	return;
}