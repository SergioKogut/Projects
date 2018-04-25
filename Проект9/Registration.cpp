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
	cout << "������  ����: ";
	cin >> obj.day;
	cout << "������  �����: ";
	cin >> obj.month;
	cout << "������ ��: ";
	cin >> obj.year;
	return input;
}

class AppAirlineTicket
{
public:
	//����������� �� ������������
	AppAirlineTicket();
	~AppAirlineTicket();

	friend ostream & operator << (ostream &out, AppAirlineTicket &obj);
	friend istream & operator >> (istream &input, AppAirlineTicket &obj);

	string const GetDestination();
	string const GetSurnameandInitials();
	int const GetFlightNumber();
	Date const GetFlightDate();


private:

	string	_Destination; //����� �����������
	int _FlightNumber; //����� �����
	string _SurnameandInitials; // ������� �� ������� ��������
	Date _FlightDate; // ������ ���� �������


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
	cout << left << setw(10) << "\n\n\n������  ����� �����������: ";
	cin >> obj._Destination;

	cout << left << setw(10) << "������ ����� �����: ";

	//�������� �� ����������� �����
	cin >> tempint;
	if (!cin.good())
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "\b";
	}
	obj._FlightNumber = tempint;
	
	cout << left << setw(10) << "������ ������� �� �������: ";
	
	
	//cin.getline(temp2, 15);
	cin.ignore();
	cin.get(temp2, 15);
	obj._SurnameandInitials = string(temp2);
	//cin >> obj._SurnameandInitials;
	cout << left << setw(10) << "����: " << endl;
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
	_Destination = "��������";
	_FlightNumber = 0;
	_SurnameandInitials = "��������";
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
	int Count; //������� ������
	int SelectionAction();
	// ���� ��� ͳ
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
			cout << "������ ����� ����� ��� ������: ";
			cin >> FindNumber;
		}	
	else if (FindWord == "FlightDate")
		{
			cout << "������ ���� ��� ������: ";
			cin >> TempData;
		}
	
	

	cout << " --------------------------------------------------------------------------------------" << endl;
	cout << "|    �����   |    �����        |    �����     |    �������      |        ������       |" << endl;
	cout << "|   �������  |   �����������   |    �����    |   �� �������    |     ���� �������    |" << endl;
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

auto RegistrationApplication::DeleteElement(list< AppAirlineTicket>& list1, int pos) // <--- ��� & ��������
{
	list< AppAirlineTicket>::iterator it = list1.begin();
	advance(it, pos); // <-- advance ����� ��������� ��������  �� k �������
	if (it != list1.end())
	{
		return list1.erase(it); // <--- ������ �������� �� k+1 �������, ����� it ��� *
	}
	return it; // k ������ ������� ������, ������� ����� end()
}

void RegistrationApplication::Run()
{
	bool flag_program = true;

	while (flag_program)
	{
		int Selection = SelectionAction();

		//䳿 � ����������� ������
		switch (Selection)
		{
			case 0: // ������  ������
			{
				//��������� ������
				AppAirlineTicket temp;
				// ������� ��������
				cin >> temp;
				// �������� � ������� ������
				Registration.push_front(temp);
				Count++;
				
				break;
			}
			case 1: // ���������  ������
			{
				int pos;
				cout << "������ ����� ������� ��� ���������: ";
				cin >> pos;
				DeleteElement(Registration, pos-1);
				break;
			}

			case 2: // ������� �� ������� �����
			{
				Print("FlightNumber");
				_getch();
				break;
			}

			case 3: // ������� �� ������� �����
			{
				Print("FlightDate");
				_getch();
				break;
			}
			case 4: // ���� ��� ������
			{
				Print();
				break;
			}
			case 5: // �����
		
			{
				bool dialog = YesNo("������ �����?");
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
	// ���� ��� ����
	int CONST H = 6;
	array<string, H> menus = { "������ ������", "�������� ������", "����� �� ������� �����","����� �� ����� �������","������� �� ������", "���i� " };
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

//--------����� ��� �--------------
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
			cout << "\t\t\t\t\t" << question << " ���  (Ͳ)" << endl;;
		}
		else
		{
			cout << "\t\t\t\t\t" << question << "(���)  Ͳ " << endl;;
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
	SetConsoleCP(1251); // ��������� ����
	SetConsoleOutputCP(1251); //  ��������� ����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	
	



	RegistrationApplication Wizzair;

	Wizzair.Run();

}