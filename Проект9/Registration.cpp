#include<iostream>
#include"conio.h"
#include <Windows.h>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <locale>
#include <numeric>
#include <random>
#include <map>
#include <list>
#include <utility> 
#include <cstdio>
#include <cstdlib>


using namespace std;

const int KEY_ARROW_UP = 72;
const int KEY_ARROW_DOWN = 80;
const int KEY_ARROW_LEFT = 75;
const int KEY_ARROW_RIGHT = 77;
const int KEY_ENTER = 13;

struct Date {

	int day;
	int month;
	int year;
	Date()
	{
		day = 1;
		month = 1;
		year = 2018;
	}

};
ostream & operator << (ostream &out, Date &obj)
{
	cout << right << obj.day << "." << obj.month << "." << obj.year;
	return out;
}
istream & operator >> (istream &input, Date &obj)
{
	cout << "Введіть  день: ";
	cin >> obj.day;
	cout << "Введіть  місяць: ";
	cin >> obj.month;
	cout << "Введіть рік: ";
	cin >> obj.year;
	return input;
}

class AppAirlineTicket
{
public:
	//конструктор по замовчуванню
	AppAirlineTicket();
	~AppAirlineTicket();

	friend ostream & operator << (ostream &out, AppAirlineTicket &obj);
	friend istream & operator >> (istream &input, AppAirlineTicket &obj);

	string const GetDestination();
	string const GetSurnameandInitials();
	int const GetFlightNumber();
	Date const GetFlightDate();


private:

	string	_Destination; //пункт призначення
	int _FlightNumber; //номер рейсу
	string _SurnameandInitials; // прізвище та ініціали пасажира
	Date _FlightDate; // бажана дата вильоту


};

ostream & operator << (ostream &out, AppAirlineTicket &obj)
{
	cout << right << setw(15) << obj._Destination << right << setw(18) << obj._FlightNumber << right << setw(20) << obj._SurnameandInitials << right << setw(15) << obj._FlightDate << endl;
	return out;
}
istream & operator >> (istream &input, AppAirlineTicket &obj)
{
	string temp;
	char temp2[30];
	int tempint = 0;
	//------------------------------------------------
	cout << left << setw(10) << "\n\n\nВведіть  пункт призначення: ";
	cin >> obj._Destination;

	cout << left << setw(10) << "Введіть номер літака: ";

	//перевірка на правильність вводу
	cin >> tempint;
	if (!cin.good())
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "\b";
	}
	obj._FlightNumber = tempint;
	
	cout << left << setw(10) << "Введіть прізвище та ініціали: ";
	
	
	//cin.getline(temp2, 15);
	cin.ignore();
	cin.get(temp2, 15);
	obj._SurnameandInitials = string(temp2);
	//cin >> obj._SurnameandInitials;
	cout << left << setw(10) << "Дата: " << endl;
	cin >> obj._FlightDate;


	return input;
}

string const AppAirlineTicket::GetDestination()
{	return _Destination;}


string const AppAirlineTicket::GetSurnameandInitials()
{
	return _SurnameandInitials;
}
int const AppAirlineTicket::GetFlightNumber()
{
	return _FlightNumber;
}
Date const AppAirlineTicket::GetFlightDate()
{
	return _FlightDate;
}

AppAirlineTicket::AppAirlineTicket()
{
	_Destination = "Невідомий";
	_FlightNumber = 0;
	_SurnameandInitials = "Невідомий";
	_FlightDate = {};

};
AppAirlineTicket::~AppAirlineTicket()
{
}


class RegistrationApplication
{
public:
	RegistrationApplication();
	~RegistrationApplication();

	
	
	void Run();

private:
	
	list< AppAirlineTicket> Registration;
	int Count; //кількість заявок
	int SelectionAction();
	// вибір Так Ні
	bool YesNo(string question);
	auto DeleteElement(list< AppAirlineTicket>& list1, int pos);
	void Print(string FindWord);


};

void RegistrationApplication::Print(string FindWord="")
{
	int FindNumber;
	Date TempData;
	if (FindWord=="FlightNumber")
		{
			cout << "Введіть номер рейса для пошуку: ";
			cin >> FindNumber;
		}	
	else if (FindWord == "FlightDate")
		{
			cout << "Введіть дату для пошуку: ";
			cin >> TempData;
		}
	
	

	cout << " --------------------------------------------------------------------------------------" << endl;
	cout << "|    Номер   |    Пункт        |    Номер     |    Прізвище      |        Бажана       |" << endl;
	cout << "|   позиції  |   призначення   |    літака    |   та ініціали    |     дата вильоту    |" << endl;
	cout << " --------------------------------------------------------------------------------------" << endl;
	
		int k = 1;
			for (list<AppAirlineTicket>::iterator it = Registration.begin(); it != Registration.end(); ++it)
			{
				if (FindWord == "FlightNumber")
				{
					if (it->GetFlightNumber() == FindNumber)
					{
						cout << internal << setw(10) << k++ << *it;
					}
				}
				else if (FindWord == "FlightDate")
				{
					if (it->GetFlightNumber() == FindNumber)
					{
						cout << internal << setw(10) << k++ << *it;
					}
				}
				else
					{
						cout << internal << setw(10) << k++ << *it;
					}
			}
		


	_getch();



}

auto RegistrationApplication::DeleteElement(list< AppAirlineTicket>& list1, int pos) // <--- Тут & появился
{
	list< AppAirlineTicket>::iterator it = list1.begin();
	advance(it, pos); // <-- advance ітерує переданий ітератор  на k позицій
	if (it != list1.end())
	{
		return list1.erase(it); // <--- Вернет итератор на k+1 элемент, перед it нет *
	}
	return it; // k больше размера списка, дефакто равет end()
}

void RegistrationApplication::Run()
{
	bool flag_program = true;

	while (flag_program)
	{
		int Selection = SelectionAction();

		//дії з регістрацією заявок
		switch (Selection)
		{
			case 0: // додаємо  заявку
			{
				//створюємо заявку
				AppAirlineTicket temp;
				// вводимо значення
				cin >> temp;
				// закидаємо у початок списку
				Registration.push_front(temp);
				Count++;
				
				break;
			}
			case 1: // видаляємо  заявку
			{
				int pos;
				cout << "Введіть номер позиції для видалення: ";
				cin >> pos;
				DeleteElement(Registration, pos-1);
				break;
			}

			case 2: // вивести за номером рейса
			{
				Print("FlightNumber");
				_getch();
				break;
			}

			case 3: // вивести за номером рейса
			{
				Print("FlightDate");
				_getch();
				break;
			}
			case 4: // Друк всіх заявок
			{
				Print();
				break;
			}
			case 5: // Вихід
		
			{
				bool dialog = YesNo("Хочете вийти?");
				if (dialog == true) flag_program = false;
				break;
			}

			default:
			{
				cout << "Please repeat\n";
				break;
			}
		}
	}
}
int RegistrationApplication::SelectionAction()
{
	// змінні для меню
	int CONST H = 6;
	array<string, H> menus = { "Додати заявку", "Видалити заявку", "Пошук за номером рейса","Пошук за датою вильоту","Вивести всі заявки", "Вихiд " };
	bool flag = true, flag_program = true;
	int ActiveM = 0;
	char ch1, ch2;

	while (flag)
	{
		system("cls");
		cout << "\n\n\n\n\n";
		for (int i = 0; i < H; i++)
		{
			if (i == ActiveM)
			{
				cout << "\t\t\t\t" << "--> " << menus[i] << endl;
			}

			else
			{
				cout << "\t\t\t\t" << "    " << menus[i] << endl;
			}
		}

		ch1 = _getch();
		if (ch1 == -32) ch2 = _getch();
		if (ch1 == -32 && ch2 == KEY_ARROW_UP && ActiveM != 0) --ActiveM;
		if (ch1 == -32 && ch2 == KEY_ARROW_DOWN && ActiveM != H - 1) ++ActiveM;
		if (ch1 == KEY_ENTER) { cout << ActiveM; flag = false; system("cls"); return ActiveM; }

	}
}

//--------діалог так ні--------------
bool  RegistrationApplication::YesNo(string question)
{
	bool flag = true;
	bool ActiveM = false;
	char ch1, ch2;

	while (flag)
	{
		system("cls");
		cout << "\n\n\n\n\n";
		if (ActiveM == false)
		{
			cout << "\t\t\t\t\t" << question << " ТАК  (НІ)" << endl;;
		}
		else
		{
			cout << "\t\t\t\t\t" << question << "(ТАК)  НІ " << endl;;
		}

		ch1 = _getch();
		if (ch1 == -32) ch2 = _getch();
		if (ch1 == -32 && ch2 == KEY_ARROW_LEFT && ActiveM != true) ActiveM = !ActiveM;
		if (ch1 == -32 && ch2 == KEY_ARROW_RIGHT&& ActiveM != false) ActiveM = !ActiveM;
		if (ch1 == KEY_ENTER)
			{
				flag = false;
				system("cls");
				return ActiveM;
			}

	}

}




RegistrationApplication::RegistrationApplication()
{
	Count = 0;
}

RegistrationApplication::~RegistrationApplication()
{
}


void main()
{
	SetConsoleCP(1251); // українська мова
	SetConsoleOutputCP(1251); //  українська мова
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	
	



	RegistrationApplication Wizzair;

	Wizzair.Run();

}