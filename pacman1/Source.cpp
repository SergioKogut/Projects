#include<iostream>
#include <fstream>
#include <locale>
#include "windows.h"
#include <ctime>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <iomanip>
using namespace std;
struct Moves
{
	int x;
	int y;

};

void SetCursorI(int x, int y, char sym);
void PrintField(char arr[][26], int nFieldHeight, int nFieldWidth);
void MoveWave(char arr[][26], int mover[][2], int GhostX, int GhostY, int PacmanX, int PacmanY);
//void wave(int arr[][25], int width, int height, int y, int x, int d);



void main()
{
	const int nFieldWidth = 26;//Size X
	const int nFieldHeight = 26;//Size Y

	char arr[nFieldHeight][nFieldWidth] =
	  { "1111111111111111111111111",//0
		"1000000000001000000000001",//1
		"1011110111101011110111101",//2
		"1011110111101011110111101",//3
		"1011110111101011110111101",//4
		"1000000000000000000000001",//5
		"1011110111111111110111101",//6
		"1011110100000000010111101",//7
		"1000000100000000010000001",//8
		"1111110111111111110111111",//9
		"1000010000000000000100001",//10
		"1111110111110111110111111",//11
		"0000000100000000010000000",//12
		"1111110111111111110111111",//13
		"1000010000000000000100001",//14
		"1111110111111111110111111",//15
		"1000000100000000010000001",//16
		"1011110100000000010111101",//17
		"1011110111111111110111101",//18
		"1000000000000000000000001",//19
		"1011110111101011110111101",//20
		"1011110111101011110111101",//21
		"1011110111101011110111101",//22
		"1000000000001000000000001",//23
		"1111111111111111111111111",//24
		"1111111111111111111111111" //25
	};

	
	int mover[50][2];
	setlocale(LC_ALL, "Russian");
	//	srand(time(0));

	cout << "Hello" << endl;



	//PrintField(arr, nFieldHeight, nFieldWidth);

	MoveWave(arr, mover, 8, 12, 23, 6);
	_getch();


}




void MoveWave(char arr[][26],int mover[][2], int GhostX, int GhostY, int PacmanX, int PacmanY)
{
	int map[25][25];
	int temparr[25][25];

	// підготовка масивів

	for (int y = 0; y < 25; y++)
	{
		for (int x = 0; x < 25; x++)
		{
			temparr[25][25] = 0;
			if (arr[y][x] == '2' || arr[y][x] == '0')   map[y][x] = 0;
			else  map[y][x] = -1;
		}
		cout << endl;
	}
	map[GhostY][GhostX] = 1;
	//map[PacmanY][PacmanX] = 0;

	// друк проміжного масиву
	for (int y = 0; y < 25; y++)
	{
		for (int x = 0; x < 25; x++)
		{
			cout << right << setw(3) << map[y][x];
		}
		cout << endl;
	}

	//wave(map, 25, 25, GhostY, GhostX, 1);
	int CountWave = 1;

	do
	{
		CountWave++;
		
	for (int y = 0; y < 25; y++)
	{
		for (int x = 0; x < 25; x++)
		{
			if (map[y][x] == CountWave-1)
			{
				if (x < 24 && map[y][x + 1] == 0) map[y][x+1] = CountWave;
				if (x > 1 && map[y][x - 1] == 0) map[y][x-1] = CountWave;
				if (y < 24 && map[y+1][x] == 0) map[y+1][x] = CountWave;
				if (y > 1 && map[y-1][x] == 0) map[y-1][x] = CountWave;
			}
		}
	}

	/*system("cls");
	cout << "Хвиля №: " << CountWave << endl;
	// друк  масиву
	for (int y = 0; y < 25; y++)
	{
		for (int x = 0; x < 25; x++)
		{
			cout << right << setw(3) << map[y][x];
		}
		cout << endl;
	}
	*/
//	_getch();

	} while (map[PacmanY][PacmanX]==0);

	//map[PacmanY][PacmanX] = CountWave + 1;
	system("cls");
	cout << "Хвиля №: " << CountWave << endl;
	// друк  масиву
	for (int y = 0; y < 25; y++)
	{
		for (int x = 0; x < 25; x++)
		{
			cout << right << setw(3) << map[y][x];
		}
		cout << endl;
	}
//------------------------------------------------------	

	int CountMoves = CountWave - 1;
	int x = PacmanX;
	int y = PacmanY;
	
	do
	{  // розробити 
		mover[CountMoves][0] = x;
		mover[CountMoves][1] = y;
//---------------------------------------------
		
		if (x < 24 && map[y][x] - map[y][x + 1] == 1)
		{
			map[y][x] = -5;
			x++;
		}
		else if (x > 1 && map[y][x] - map[y][x - 1] == 1)
		{
			map[y][x] = -5;
			x--;
		}
		else if (y < 24 && map[y][x] - map[y + 1][x] == 1)
		{
			map[y][x] = -5;
			y++;
		}
		else if (y > 1 && map[y][x] - map[y - 1][x] == 1)
		{
			map[y][x] = -5;
			y--;
		}
//-------------------------------------------------------------		
				CountMoves--;
				system("cls");
				for (int y = 0; y < 25; y++)
				{
					for (int x = 0; x < 25; x++)
					{
						cout << right << setw(3) << map[y][x];
					}
					cout << endl;
				}
			//	_getch();
//-------------------------------------------------------------


	} while ((x!= GhostX) || (y!= GhostY));

	cout << "Шлях  " << endl;
	for (int i = CountWave - 1; i >0 ; i--)
	{
		cout << "x=" << mover[i][0] << " y=" << mover[i][1] << endl;
	}

	
}

//void wave(int arr[][25],Moves a, int width,int height, int y, int x, int d) {
//	arr[y][x] = d;
//
//	//for (int i = y - 1; i <= y + 1; i++) {
//		//for (int j = x - 1; j < x + 1; j++) {
//			if (x < width  && arr[y][x + 1] == 0)
//					{
//				wave(arr, 25, 25, y, x + 1, d + 1);
//					}
//			if (y > 0 && arr[y - 1][x] == 0) 
//					{
//						wave(arr, 25, 25, y - 1, x, d + 1);
//					}
//			if (y < height && arr[y + 1][x] == 0) {
//				wave(arr, 25, 25, y + 1, x, d + 1);
//			}
//			if (x > 0 && arr[y][x - 1] == 0) {
//				wave(arr, 25, 25, y, x-1, d + 1);
//		//	}
//	//	}
//
//	}
//
//}










void PrintField(char arr[][26], int nFieldHeight, int nFieldWidth)
{


	for (int y = 0; y < nFieldHeight - 1; y++)
	{
		for (int x = 0; x < nFieldWidth - 1; x++)
		{

			if (arr[y][x] == '1')  SetCursorI(y, x * 2, '#');
			else  SetCursorI(y, x * 2, ' ');

		}
		cout << endl;
	}


}



void SetCursorI(int x, int y, char sym)
{
	COORD cursorPos = { y,x };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
	cout << sym;
}