
#include<iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <locale>
#include <iomanip>
#include <Windows.h>
#include"conio.h"
#include <Windows.h>
#include <math.h>


const int KEY_ARROW_UP = 72;
const int KEY_ARROW_DOWN = 80;
const int KEY_ARROW_LEFT = 75;
const int KEY_ARROW_RIGHT = 77;
const int KEY_ENTER = 13;

using namespace std;

using std::cout;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::endl;
using std::ios;
using std::string;

class Phone
{
public:
	Phone();
	Phone(const Phone &obj);
	Phone(int number, int cod, string typephone, string Operator, string person);
	~Phone();
	void Print();

protected:
	int _number; //номер телефона
	int _cod; // код оператора
	string _TypePhone; // тип телефону міський чи мобільний
	string _Operator;// назва оператора
	string _Person;//ПІБ абонента
};

Phone::Phone(const Phone &obj)
{
	this->_cod = obj._cod;
	this->_number = obj._number;
	this->_TypePhone = obj._TypePhone;
	this->_Operator = obj._Operator;
	this->_Person = obj._Person;
}

void Phone::Print()
{
	cout << _TypePhone << ": " << _cod << "-" << _number << "  " << _Operator << "    " << _Person << endl;
}

Phone::Phone() :_number(0), _cod(0), _TypePhone("Noname"), _Operator("Noname"), _Person("Noname")
{
}
Phone::Phone(int number, int cod, string typephone, string Operator, string person) : _number(number), _cod(cod), _TypePhone(typephone), _Operator(Operator), _Person(person)
{
}


Phone::~Phone()
{
}


class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void Run();


	int menu();
	bool  YesNo(string question);
private:
	vector<Phone>  PhoneBook1;
	void Print();
	void AddCityPhone();
	void AddCellPhone();
	void SavePhoneBook();
	void LoadPhoneBook();

};

int PhoneBook::menu()
{
	// змінні для меню
	int CONST H = 6;
	array<string, H> menus = { "Додати міський телефон",
		"Додати мобільний телефон",
		"Вивести всі телефони",
		"Записати телефони у файл",
		"Завантажити телефони з файла",
		"Вихiд " };
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
bool  PhoneBook::YesNo(string question)
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
		if (ch1 == -32 && ch2 == KEY_ARROW_RIGHT && ActiveM != false) ActiveM = !ActiveM;
		if (ch1 == KEY_ENTER)
		{
			flag = false;
			system("cls");
			return ActiveM;
		}

	}

}




void PhoneBook::Print()
{

	if (!PhoneBook1.empty())
	{
		for (auto it : PhoneBook1)
		{
			it.Print();
		}

	}
	else
	{
		cout << "Телефонів в базі немає!";

	}
	_getch();

}

void PhoneBook::Run()
{





	bool flag_program = true;

	while (flag_program)
	{
		int Selection = menu();

		//дії з регістрацією заявок
		switch (Selection)
		{
		case 0: // добавити міський  телефон
		{
			AddCityPhone();
			break;
		}
		case 1: // добавити мобільний телефон
		{
			AddCellPhone();
			break;
		}

		case 2: // вивести всі телефони
		{
			Print();
			break;
		}

		case 3:  // записати телефони
		{
			SavePhoneBook();
			break;
		}
		case 4:// завантажити телефони
		{
			LoadPhoneBook();
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

void PhoneBook::AddCityPhone()
{

	PhoneBook1.push_back(Phone(644635, 362, "City", "Rivne", "Kohut S.V."));
}

void PhoneBook::AddCellPhone()
{
	PhoneBook1.push_back(Phone(7968934, 97, "Cell", "Kievstar", "Kohut S.V."));
}

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::SavePhoneBook()
{
	// Object to write in file

	if (!PhoneBook1.empty())
	{
		ofstream file_obj;

		// Opening file in append mode
		file_obj.open("telephone.txt", ios::app);

		for (auto element : PhoneBook1)
		{
			//file_obj.write(reinterpret_cast<const char*>(&element), sizeof(*element));
			file_obj.write((char*)&element, sizeof(element));
		}


		cout << "Телефони записано!";
		file_obj.close();
	}
	else
	{
		cout << "Запис в файл неможливий, оскільки база телефонів не заповнена!";

	}

	_getch();


}

void PhoneBook::LoadPhoneBook()
{

	// Object to read from file
	ifstream file_obj;

	// Opening file in input mode
	file_obj.open("telephone.txt", ios::in);
	file_obj.clear();
	Phone  obj;

	// Checking till we have the feed
	// while (!file_obj.eof())
	//{
	//file_obj.read((char*)&obj, sizeof(obj));
	//PhoneBook1.push_back(obj);
	//} 
	//file_obj.read((char*)&obj, sizeof(obj))
	//file_obj.read(reinterpret_cast<char *>(&obj), sizeof(obj));

	while (file_obj.read((char*)&obj, sizeof(obj)))
	{
		PhoneBook1.push_back(obj);
	}


	file_obj.close();

}


int main()
{
	SetConsoleCP(1251); // українська мова
	SetConsoleOutputCP(1251); //  українська мова
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);


	PhoneBook One;

	One.Run();


	return 0;
}


