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

const int COLUMN = 80;
const int ROW = 25;
const int WIN_LENGHT = 20;

const int KEY_ARROW_UP = 72;
const int KEY_ARROW_DOWN = 80;
const int KEY_ARROW_LEFT = 75;
const int KEY_ARROW_RIGHT = 77;
const int KEY_ENTER = 13;
enum Key { Left, Right, Up, Down };


void StartParameters();
void start();
void PrintZmiika();


void PrintField(char a[][26], int x, int y);
bool bNextField(char a[][26], int nPosX, int nPosY, char sym);
void Keypressed(bool* pbKey,int* pCurrentKey, int* pNextKey);


void InputField(int x, int y);



void SetColor(int color);
void SetCursor(int x, int y, char sym);
void SetCursorI(int x, int y, char sym);
void SetCursorX(int x, int y, string sym);
void SetCursorZ(int x, int y);


void HorizontalLine(int xLeft, int xRight, int y, int sym);
void VerticalLine(int yDown, int yUp, int x, int sym);

int menu2(int x, int y);
void poz(int k1 = 0, int k2 = 0);
bool menuYesNo();
void DrawSnake(int* arrX, int* arrY, int* lenght);
void RepeatSnake(int* arrX, int* arrY, int* lenght);
void DrawSnakeTwo(int* arrX, int* arrY, int* lenght);
void KeyPressedSnake(int* pdX, int*  pdY);
void RebuildSnake(int* arrX, int* arrY, int* pdX, int*  pdY, int* lenght);
void DrawFood(int* arrX, int* arrY, int* lenght, int* foodX, int* foodY);
void SaveInFile(ofstream &File, string* Gamer, int* pmaxlenght);
void LoadFromFile(ifstream  &File1, string* Gamer, int* pmaxlenght);
void Table_Rezult(string* Gamer, int* pmaxlenght, int* size);
void Table_Instruction();

void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	StartParameters();
	start();

}

void StartParameters()
{
//	SetConsoleTitle(L" ГРА  ЗМІЙКА");
//	HANDLE OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	//int X = 40;
	//int Y = 40;
	//SMALL_RECT ConsoleRect;
	//ConsoleRect.Top = 0;
	//ConsoleRect.Left = 0;
	//ConsoleRect.Right = X - 1;
	//ConsoleRect.Bottom = Y - 1;
	//COORD BufSize;
	//BufSize.X = X;
	//BufSize.Y = Y;
	//SetConsoleScreenBufferSize(OutputHandle, BufSize);
	//SetConsoleWindowInfo(OutputHandle, TRUE, &ConsoleRect);

	//CONSOLE_FONT_INFOEX fontInfo;
	////GetCurrentConsoleFontEx(OutputHandle, TRUE, &fontInfo); // Получить текущий шрифт

	//// Поменять какие-то параметры
	////	wcsncpy(L"Consolas", fontInfo.FaceName, LF_FACESIZE);  // Имя
	//fontInfo.dwFontSize.Y = 24; // Размер (в логических единицах)

	//SetCurrentConsoleFontEx(OutputHandle, TRUE, &fontInfo); // Установить новый




}

void start()
{
	//// Основні параметри 

	//int arrX[50] = { 29,28,27 }; //масив координах Х
	//int arrY[50] = { 15,15,15 }; //масив координах Y
	//float Vx = 1.5;
	//string Gamer[10] = {};
	//int maxlenght[10] = {};
	//string* pGamer = Gamer; // вказівник на масив Х
	//int* pmaxlenght = maxlenght; // вказівник на масив Y
	//int foodX;//координата Х їжі
	//int foodY;//координата Y їжі
	//int* pfoodX = &foodX;//координата Х їжі
	//int* pfoodY = &foodY;//координата Y їжі
	//int lenght = 3; // довжина змійки
	//int* pX = arrX; // вказівник на масив Х
	//int* pY = arrY; // вказівник на масив Y
	//int* pLenght = &lenght;
	//int dX = 1; // змінна по Х
	//int dY = 0; // змінна по Y
	//int* pdX = &dX;
	//int* pdY = &dY;
	//int Life = 3;
	//int* pLife = &Life;
	bool  flag = true, flag_program = true;
	int ActiveM = 0;

	//

	int nScreenWidth = 80;			// Console Screen Size X (columns)
	int nScreenHeight = 30;			// Console Screen Size Y (rows)
	const int nFieldWidth = 26;//Size X
	const int nFieldHeight = 26;//Size Y

	int nCurrentX = 20;
	int nCurrentY = 14;
	int nCurrentKey = -1;
	int nNextKey = -1;
	int* pCurrentKey = &nCurrentKey;
	int* pNextKey = &nNextKey;

	int nSpeed = 20;
	int nSpeedCount = 0;
	bool bGameOver = false;
	bool bKey[4] = { false ,false ,false ,false };
	bool* pbKey = bKey;
	//char **pField = nullptr;
	//
	//wchar_t *screen = new wchar_t[nScreenWidth*nScreenHeight];
	//for (int i = 0; i < nScreenWidth*nScreenHeight; i++) screen[i] = L' ';
	//HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	//SetConsoleActiveScreenBuffer(hConsole);
	//DWORD dwBytesWritten = 0;





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








	while (flag_program)// головний цикл 

	{

		ActiveM = menu2(20, 7);

		// Перелік виконаних задач
		switch (ActiveM)
		{

		case 0:

		{
			// початковы дані для гри 



			PrintField(arr, nFieldHeight, nFieldWidth);

			SetCursorI(nCurrentY, nCurrentX, '@');
			while (!bGameOver)
			{
				// ------------------------Таймінг--------------------------------------------------------------------------

				Sleep(100);

				// ------------------------Перевірка нажимання клавіш-------------------------------------------------------


				int tempX = nCurrentX; int tempY = nCurrentY;
				Keypressed(pbKey, pCurrentKey, pNextKey);
				nCurrentX -= (bKey[Left] && bNextField(arr, nCurrentX / 2 - 1, nCurrentY, '0')) ? 2 : 0;
				nCurrentX += (bKey[Right] && bNextField(arr, nCurrentX / 2 + 1, nCurrentY, '0')) ? 2 : 0;
				nCurrentY -= (bKey[Up] && bNextField(arr, nCurrentX / 2, nCurrentY - 1, '0')) ? 1 : 0;
				nCurrentY += (bKey[Down] && bNextField(arr, nCurrentX / 2, nCurrentY + 1, '0')) ? 1 : 0;

				if (tempX != nCurrentX || tempY != nCurrentY) { SetCursorI(tempY, tempX, ' '); SetCursorI(nCurrentY, nCurrentX, '@'); }


				// ------------------------ ВИГРАШ ГРИ-----------------------------------------------------------------------





				// ------------------------ЗАКІНЧЕННЯ ГРИ АБО ФОРМУВАННЯ НОВОГО РАУНДУ---------------------------------------
			}


			flag = true;
			_getch();
			break;
		}
		case 1:
		{
			SetCursorI(2, 20, '5');






			flag = true;
			_getch();
			break;
		}
		case 2:
		{

			Table_Instruction();
			_getch();
			flag = true;
			break;
		}


		case 3:
		{
			// ------------------------ВИХІД З  ГРИ-------------------------------------------------------------------		

			bool dialog = menuYesNo();
			if (dialog == true) flag_program = false;

			break;
		}

		default:
		{
			//cout << "Please repeat\n";
			break;
		}

		}



	}


}
void SetColor(int color)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (color)
	{
	case 0:

	{
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		break;
	}

	case 1:

	{
		SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		break;
	}
	default:
		break;
	}



}
void SetCursor(int x, int y, char sym)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPos = { x,y };
	SetConsoleCursorPosition(hStdOut, cursorPos);
	cout << sym;
}
void SetCursorI(int x, int y, char sym)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPos = { y,x };
	SetConsoleCursorPosition(hStdOut, cursorPos);
	cout << sym;
}
void SetCursorZ(int x, int y)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPos = { x,y };
	SetConsoleCursorPosition(hStdOut, cursorPos);

}
void SetCursorX(int x, int y, string sym)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPos = { x,y };
	SetConsoleCursorPosition(hStdOut, cursorPos);
	cout << sym;



}

void HorizontalLine(int xLeft, int xRight, int y, int sym)
{

	for (int x = xLeft; x <= xRight; x++)
	{
		SetCursor(x, y, sym);
	}

}
void VerticalLine(int yDown, int yUp, int x, int sym)
{
	for (int y = yDown; y <= yUp; y++)
	{
		SetCursor(x, y, sym);
	}

}

void DrawSnake(int* arrX, int* arrY, int* lenght)
{
	for (int i = 0; i < *lenght; i++)
		SetCursor(*(arrX + i), *(arrY + i), ' ');
}
void DrawSnakeTwo(int* arrX, int* arrY, int* lenght)
{

	for (int i = 0; i < *lenght; i++)
		SetCursor(*(arrX + i), *(arrY + i), 'O');
	SetCursor(*(arrX + *lenght), *(arrY + *lenght), ' ');



}
void RepeatSnake(int* arrX, int* arrY, int* lenght)
{
	int X[10] = { 29,28,27,26,25,24,23,22 }; //масив координах Х
	int Y[10] = { 15,15,15,15,15,15,15,15 }; //масив координах Y
	int Lpoch = 3; // довжина змійки
	for (int i = 0; i < *lenght; i++)
	{
		*(arrX + i) = X[i];
		*(arrY + i) = Y[i];
		*lenght = Lpoch;
	}

}

void DrawFood(int* arrX, int* arrY, int* lenght, int* foodX, int* foodY)
{
	bool flag_food = true;


	do
	{
		*foodX = 5 + rand() % 70;
		*foodY = 10 + rand() % 14;

		// перевірка чи їжа не попала на змійку

		for (int i = 1; i < *lenght; i++)
		{
			if (*foodX == *(arrX + i) && *foodY == *(arrY + i)) flag_food = false;
		}

	} while (flag_food != true);

	SetCursor(*foodX, *foodY, '$');


}


void KeyPressedSnake(int* pdX, int*  pdY)
{
	char ch1, ch2;


	if (_kbhit())
	{

		switch (_getch())
		{
		case KEY_ARROW_UP:
		{
			if (*pdY != 1)
			{
				*pdY = -1;
				*pdX = 0;

			}
			break;
		}
		case KEY_ARROW_DOWN:
		{
			if (*pdY != (-1))
			{
				*pdY = 1;
				*pdX = 0;

			}
			break;
		}
		case KEY_ARROW_LEFT:
		{
			if (*pdX != 1)
			{
				*pdX = -1;
				*pdY = 0;

			}
			break;
		}
		case KEY_ARROW_RIGHT:
		{
			if (*pdX != (-1))
			{
				*pdX = 1;
				*pdY = 0;

			}
			break;
		}
		case 'p':
		{
			_getch();
			break;
		}


		default:			break;
		}



	}


}

void RebuildSnake(int* arrX, int* arrY, int* pdX, int*  pdY, int* lenght)
{
	int firstX = *arrX + *pdX;
	int firstY = *arrY + *pdY;

	for (int j = *lenght; j >0; j--)
	{
		*(arrX + j) = *(arrX + j - 1);
		*(arrY + j) = *(arrY + j - 1);
	}

	*arrX = firstX;
	*arrY = firstY;
}

void PrintField(char a[][26], int nFieldHeight, int nFieldWidth)
{


	for (int y = 0; y <nFieldHeight - 1; y++)
	{
		for (int x = 0; x < nFieldWidth - 1; x++)
		{

			//if (a[x][y] == '1') cout << "O";
			//else cout << ' ';

			if (a[y][x] == '1')  SetCursorI(y, x * 2, '#');
			else  SetCursorI(y, x * 2, ' ');

		}
		cout << endl;
	}


}

bool bNextField(char a[][26], int nPosX, int nPosY, char sym)
{
	bool field;
	if (a[nPosY][nPosX] == sym)
	{
		return true;
	}
	else
	{
		return false;
	}


}
void  Keypressed(bool* pbKey, int* pCurrentKey, int* pNextKey)
{
	 


	if (_kbhit())
	{
		//pbKey[*pNextKey] = true;
		 if (*pCurrentKey!=0) pbKey[*pCurrentKey] = true;	
		//pbKey[Left] = false; pbKey[Right] = false; pbKey[Up] = false; pbKey[Down] = false;
		switch (_getch())
		{
		case KEY_ARROW_LEFT:
		{
			pbKey[Left] = true;
			*pNextKey = *pCurrentKey;
			*pCurrentKey = Left;
			break;
		}
		case KEY_ARROW_RIGHT:
		{
			pbKey[Right] = true;
			*pNextKey = *pCurrentKey;
			*pCurrentKey = Right;
			break;
		}
		case KEY_ARROW_UP:
		{
			pbKey[Up] = true; 
			*pNextKey = *pCurrentKey;
			*pCurrentKey = Up;
			break;
		}
		case KEY_ARROW_DOWN:
		{
			pbKey[Down] = true;
			*pNextKey = *pCurrentKey;
			*pCurrentKey = Down;
			break;
		}
		case 'p':
		{
			_getch();
			break;
		}


		default:			break;
		}



	}





}


void InputField(int x, int y)
{

	bool flag_exit = true;

	char ch1, ch2;
	int dX = x + 1, dY = y;
	SetCursorZ(x + 1, y);

	while (flag_exit)
	{

		if (_kbhit())
		{
			SetCursorZ(5, 5); cout << dX;
			SetCursorZ(5, 7); cout << dY;

			switch (_getch())

			{


			case KEY_ARROW_UP:
			{
				if (dY>y)
				{
					dY--;
					if ((dY == y + 3) || (dY == y + 7)) dY--;
				}
				SetCursorZ(dX, dY);
				break;

			}
			case KEY_ARROW_DOWN:
			{
				if (dY<y + 10)
				{
					dY++;
					if ((dY == y + 3) || (dY == y + 7)) dY++;
				}

				SetCursorZ(dX, dY);
				break;
			}
			case KEY_ARROW_LEFT:
			{
				if (dX>x + 1)
				{
					dX -= 2;
				}

				SetCursorZ(dX, dY);
				break;
			}
			case KEY_ARROW_RIGHT:
			{
				if (dX<x + 17)
				{
					dX += 2;
				}

				SetCursorZ(dX, dY);
				break;
			}



			case	KEY_ENTER:
			{

				SetCursorZ(dX, dY);

				break;
			}
			case 'p':
			{
				flag_exit = false;
				_getch();
				break;
			}

			case '1': {SetCursor(dX, dY, '1');	break; }
			case '2': {SetCursor(dX, dY, '2');	break; }
			case '3': {SetCursor(dX, dY, '3');	break; }
			case '4': {SetCursor(dX, dY, '4');	break; }
			case '5': {SetCursor(dX, dY, '5');	break; }
			case '6': {SetCursor(dX, dY, '6');	break; }
			case '7': {SetCursor(dX, dY, '7');	break; }
			case '8': {SetCursor(dX, dY, '8');	break; }
			case '9': {SetCursor(dX, dY, '9');	break; }


			default:	break;


			}



		}




	}






}



int menu2(int x, int y) //тип виводу меню
{


	// змінні для меню
	int CONST H = 4;
	string menus[H] = { "Старт гри", "Результати", "Iнструкцiя", "Вихiд   " }; // масив меню

	bool flag = true, flag_program = true;
	int ActiveM = 0;
	char ch1, ch2;

	SetColor(0);





	while (flag)
	{
		//system("cls");

		for (int i = 0; i < H; i++)
		{
			if (i == ActiveM)
			{
				SetColor(1);
				SetCursor(x, y + i, ' ');
				cout << "--> " << menus[i] << " <--" << endl;

			}

			else
			{
				SetColor(0);
				SetCursor(x, y + i, ' ');
				cout << "    " << menus[i] << "    " << endl;
			}
		}

		ch1 = _getch();
		if (ch1 == -32) ch2 = _getch();
		if (ch1 == -32 && ch2 == KEY_ARROW_UP && ActiveM != 0) --ActiveM;
		if (ch1 == -32 && ch2 == KEY_ARROW_DOWN && ActiveM != H - 1) ++ActiveM;
		if (ch1 == KEY_ENTER) { cout << ActiveM; flag = false; system("cls"); return ActiveM; }

	}





}
void poz(int k1, int k2)
{
	for (int i = 0; i < k1; i++) cout << endl;
	for (int j = 0; j < k2; j++) cout << "\t";
} // 
bool menuYesNo()
{





	bool flag = true, flag_program = true;
	bool ActiveM = false;
	char ch1, ch2;

	SetColor(0);

	while (flag)
	{
		system("cls");
		poz(7);


		if (ActiveM == false)
		{
			SetColor(1);
			cout << "\t\t\t\t\t  Бажаєте вийти з гри?" << endl;
			cout << "\t\t\t\t\t\t" << "ТАК ";
			SetColor(0);
			cout << " НI" << endl;
		}

		else
		{
			SetColor(1);
			cout << "\t\t\t\t\t  Бажаєте вийти з гри?" << endl;
			SetColor(0);
			cout << "\t\t\t\t\t\t" << "ТАК ";
			SetColor(1);
			cout << " НI" << endl;
		}

		//&& ActiveM != true && ActiveM != false
		ch1 = _getch();
		if (ch1 == -32) ch2 = _getch();
		if (ch1 == -32 && ch2 == KEY_ARROW_LEFT && ActiveM != true) ActiveM = !ActiveM;
		if (ch1 == -32 && ch2 == KEY_ARROW_RIGHT&& ActiveM != false) ActiveM = !ActiveM;
		if (ch1 == KEY_ENTER)
		{
			//cout << ActiveM;
			flag = false;
			system("cls");
			return ActiveM;
		}

	}







	/*	int result;
	SetColor(0);
	char m = _getch();

	while (m != char(13))
	{
	SetCursor(8, 10, ' ');
	cout << "Хочете вийти? Виберiть ->    <- \n";


	if (m == char(224))
	{
	switch (_getch())
	{
	case 75:
	{
	SetColor(0);
	cout << "ТАК";
	SetColor(1);
	cout << "|";
	cout << "НI\n";
	result = 0;
	break;
	}
	case 77:
	{

	cout << "ТАК";
	cout << "|";
	SetColor(1);
	cout << "НI\n";
	SetColor(0);
	result = 1;
	break;
	}
	}
	}
	m = _getch();
	system("cls");
	}
	return result;*/
}
void PrintZmiika()
{
	cout << "                                    O       OOO							" << endl;
	cout << "         																	" << endl;
	cout << "             OOOO   O           O   O   O         O   O     O     OOOOO	" << endl;
	cout << "            O    O  O O       O O   O   O       O O   O   O      O    O	" << endl;
	cout << "                O   O   O   O   O   O   O     O   O   O O       O     O	" << endl;
	cout << "                 O  O     O     O   O   O   O     O   O  O      O O O O	" << endl;
	cout << "            O    O  O           O   O   O O       O   O    O    O     O	" << endl;
	cout << "             OOOO   O           O   O   O         O   O     O   O     O	" << endl << endl << endl;


}

void SaveInFile(ofstream  &File, string* Gamer, int* pmaxlenght)
{

	File.open("spisok.txt", ios_base::app); // любой текстовый файл в твоём проекте
	if (File.fail())
	{
		cout << "\n Помилка відкриття  файла";
		exit(1);
	}
	File << *Gamer << endl;//записываем переменную в файл
	File << *pmaxlenght << endl;//записываем переменную в файл

	File.close();//Закрываем файл


	cout << "Файл записаний" << endl;







}
void LoadFromFile(ifstream  &File1, string* Gamer, int* pmaxlenght)
{
	File1.open("spisok.txt", ios_base::in); // любой текстовый файл в твоём проекте
	if (File1.fail())
	{
		cout << "\n Помилка відкриття  файла";
		exit(1);
	}

	File1 >> *Gamer;
	File1 >> *pmaxlenght;

	//cout << *Gamer << endl;
	//cout <<(int)*pmaxlenght << endl;

	File1.close();
}

void Table_Rezult(string* Gamer, int* pmaxlenght, int* size)
{
	int i = 1;
	poz(5);
	cout << "\t\t\t\t        Найкращi результати гри:" << endl;
	cout << "\t\t\t _____________________________________________________ " << endl;
	cout << "\t\t\t| № п/п  |      Назва гравця       |  Довжина змiйки  |" << endl;
	cout << "\t\t\t|________|_________________________|__________________|" << endl;
	for (int i = 0; i < *size; i++)
	{
		cout << "\t\t\t|   " << setw(5) << left << i + 1 << "|  " << setw(23) << *(Gamer + i) << "|       " << setw(11) << *(pmaxlenght + i) << "|" << endl;
	}
	cout << "\t\t\t|________|_________________________|__________________|" << endl;



}
void Table_Instruction()
{
	poz(5);
	cout << "\t\t\t\t              Iнструкцiя			" << endl;
	cout << "\t\t\t _____________________________________________________ " << endl;
	cout << "\t\t\t|               Навiгацiя по меню:                    |" << endl;
	cout << "\t\t\t|           Клавiши: [ВВЕРХ] , [ВНИЗ]                 |" << endl;
	cout << "\t\t\t|                                                     |" << endl;
	cout << "\t\t\t|         Управлiння змiйкою  в грі:                  |" << endl;
	cout << "\t\t\t|  Клавiши: [ВВЕРХ] , [ВНИЗ]  , [ВЛІВО] , [ВПРАВО]    |" << endl;
	cout << "\t\t\t|            [Р]- пауза                               |" << endl;
	cout << "\t\t\t|                                                     |" << endl;
	cout << "\t\t\t|    Змiйка хоче їсти! Вiд цього вона росте!          |" << endl;
	cout << "\t\t\t|    При досягненнi довжини 20 - ви виграєте!         |" << endl;
	cout << "\t\t\t|                   Успiху Вам!                       |" << endl;
	cout << "\t\t\t|_____________________________________________________|" << endl;




}