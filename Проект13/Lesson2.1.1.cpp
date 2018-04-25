#include<iostream>
#include<string>
#include<vector>
#include"conio.h"
#include <Windows.h>
#include <iomanip>
#include <algorithm>
#include <list>

using namespace std;

class IWorker // Абстрактний інтерфейсний клас
{
public:
	virtual void Print() const = 0;
	virtual void Input() = 0;
	virtual float CallSalary() const = 0;
	virtual  int GetPosition() const = 0;
	virtual	void SetPosition(int position) = 0;
	virtual	void SetSalary(float salary) = 0;

	IWorker();
	virtual ~IWorker();
};

IWorker::IWorker()
{
}
IWorker::~IWorker()
{
}



class Worker : public IWorker
{
public:
	Worker();
	Worker(string name, float salary);
	Worker(Worker &obj);
	virtual ~Worker();
	static int const GetCount();
	static int const GetMaxID();
	string   GetName() const;
	int   GetPosition() const ;
	void Print() const;
	void SetName(string Name);
	void SetPosition(int position);
	void SetSalary(float salary);

protected:
	static int _counterID;
	static int _counter;
	int _ID;
	string _name;
	string _typeworker;
	int _position;
	float _salary;

};

void Worker::Print() const
{
	cout << setw(7) << right <<this->_position << setw(13) << this->_ID << setw(16) << this->_name << setw(10) << this->_salary << endl;
}

void Worker::SetSalary(float salary)
{
	this->_salary = salary;

}
void Worker::SetName(string Name)
{
	this->_name = Name;
}
void Worker::SetPosition(int position)
{
	this->_position = position;
}
int  Worker::GetPosition() const
{
	return _position;
}
string  Worker::GetName() const
{
	return _name;
}
int const Worker::GetMaxID()
{
	return _counterID;
}
int const Worker::GetCount()
{
	return _counter;
}

Worker::Worker(string name, float salary) :_name(name), _salary(salary),_typeworker("unknown")
{
	_counterID++;
	_counter++;
	this->_ID = _counterID;
	this->_position = _counter;
}
Worker::Worker() :_name("Noname"), _salary(0), _typeworker("unknown")
{
	_counterID++;
	_counter++;
	this->_ID = _counterID;
	this->_position = _counter;
}
Worker::Worker(Worker &obj)
{
	this->_ID = obj._ID;
	this->_name = obj._name;
	this->_position = obj._position;
	this->_salary = obj._salary;
}

Worker::~Worker()
{
	cout << "Deleted worker!" << endl;
	_getch();
	_counter--;
}


class TarifWorker : public  Worker
{
public:
	TarifWorker();
	TarifWorker(int tarif, int bonus);
	~TarifWorker();
	float CallSalary() const override;
	void Input();
	void Print() const override;
 private:
	int _Tarif;
	int _Bonus;

};

void TarifWorker::Print() const
{
	
	TarifWorker* HWorker = dynamic_cast<TarifWorker*>(const_cast<TarifWorker*>(this));
	cout << setw(7) << right << this->_position
		<< setw(13) << this->_ID
		<< setw(16) << this->_name
		<< setw(8) << this->_salary
		<< setw(18) << this->_typeworker
		<< setw(12) << HWorker->_Tarif
		<< setw(18) << HWorker->_Bonus << endl;
}

 
void TarifWorker::Input()
{
	string tempname;
	cout << "Enter name:";
	cin >> tempname;
	this->SetName(tempname);
	cout << "Enter tarif:";
	cin>> _Tarif;
	cout << "Enter bonus:";
	cin >> _Bonus;
	this->SetSalary(CallSalary());

}

float TarifWorker::CallSalary() const
{
	return (_Tarif + _Bonus);
}

TarifWorker::TarifWorker() :_Tarif(0), _Bonus(0)
{
	this->_typeworker = "TarifWorker";
}
TarifWorker::TarifWorker(int tarif, int bonus) : _Tarif(tarif), _Bonus(bonus)
{
	this->_typeworker = "TarifWorker";
}

TarifWorker::~TarifWorker()
{
}

class HourlyWorker : public  Worker
{
public:
	HourlyWorker();
	HourlyWorker(int hours,int payhours);
	~HourlyWorker();
	float  CallSalary() const override;
	void Input();
	void Print() const override;

private:
	int _Hours;
	int _PayHours;
};

void HourlyWorker::Print() const
{
	//IWorker *HWorker = const_cast<HourlyWorker*>(this);
	HourlyWorker* HWorker = dynamic_cast<HourlyWorker*>(const_cast<HourlyWorker*>(this));
	cout << setw(7) << right << this->_position
		 << setw(13) << this->_ID 
		 << setw(16) << this->_name
		 << setw(8) << this->_salary
		 << setw(18) << this->_typeworker
		 << setw(16) << HWorker->_Hours
		 << setw(18) << HWorker->_PayHours << endl;
}


void HourlyWorker::Input()
{
	string tempname;
	cout << "Enter name:";
	cin >> tempname;
	this->SetName(tempname);
	cout << "Enter hours in month:";
	cin >> _Hours;
	cout << "Enter pay for one hour:";
	cin >> _PayHours;
	this->SetSalary(CallSalary());

}

float HourlyWorker::CallSalary() const
{
	return _Hours*_PayHours;
}
HourlyWorker::HourlyWorker():_Hours(0), _PayHours(0)
{
	this->_typeworker = "HourlyWorker";
}

HourlyWorker::HourlyWorker(int hours, int payhours): _Hours(hours), _PayHours(payhours)
{
	this->_typeworker = "HourlyWorker";
}

HourlyWorker::~HourlyWorker()
{
}


class Department
{
public:
	Department();
	~Department();
	void Menu();

private:

	vector<IWorker*> Workers;
	vector<string> MenuItem;

	void AddHourlyWorker();
	void AddTarifWorker();

	void DelWorker();
	void Print();
	void Info();

	//змінні по меню
	int ActiveM; // активна вкладка
	int CountItemMenu; // кількість вкладок
	bool flagMenu; // флаг виходу з меню
	bool flagEnd; // флаг виходу з програми

	const int KEY_ARROW_UP = 72;
	const int KEY_ARROW_DOWN = 80;
	const int KEY_ENTER = 13;

	// метод виводу  текст кольолором
	void SetTextColor(string text, int color);

};

void Department::SetTextColor(string text, int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << "\t\t\t" << text << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
}
void Department::Menu()
{
	// змінні для меню
	MenuItem.push_back("Add hourly worker");
	MenuItem.push_back("Add tarif worker");
	MenuItem.push_back("Del worker");
	MenuItem.push_back("Print worker");
	MenuItem.push_back("Info about workers");
	MenuItem.push_back("Exit");

	char ch1, ch2;

	while (flagEnd)
	{
		while (flagMenu)
		{
			system("cls");
			cout << "\n\n\n\n\n";
			SetTextColor("   - MENU -", 14);
			for (int i = 0; i < CountItemMenu; i++)
			{
				if (i == ActiveM)
					SetTextColor(MenuItem[i], 12);
				else
					SetTextColor(MenuItem[i], 14);
			}

			ch1 = _getch();
			if (ch1 == -32) ch2 = _getch();
			if (ch1 == -32 && ch2 == KEY_ARROW_UP && ActiveM != 0) --ActiveM;
			if (ch1 == -32 && ch2 == KEY_ARROW_DOWN && ActiveM != CountItemMenu - 1) ++ActiveM;
			if (ch1 == KEY_ENTER) { cout << ActiveM; flagMenu = false; system("cls"); }
		}


		switch (ActiveM)
		{
		case 0:
		{
			AddHourlyWorker();
			cout << "Worker add!";
			_getch();
			break;
		}

		case 1:
		{
			AddTarifWorker();
			cout << "Worker add!";
			_getch();
			break;
		}

		case 2:
		{
			DelWorker();
			_getch();
			break;
		}
		case 3:
		{
			Print();
			_getch();
			break;
		}
		case 4:
		{
			Info();
			_getch();
			break;
		}
		case 5:
		{
			flagEnd = false;
			break;
		}

		default:
			break;
		}

		flagMenu = true;
	}

}

void Department::AddHourlyWorker()
{
	IWorker* temp=new HourlyWorker;
	temp->Input();
	Workers.push_back(temp);

}

void Department::AddTarifWorker()
{
	IWorker* temp = new TarifWorker;
	temp->Input();
	Workers.push_back(temp);

}



void Department::DelWorker()
{
	if (!Workers.empty())
	{
		int PositionDel;
		cout << "Enter position worker for delete:";
		cin >> PositionDel;

		if ((PositionDel < 1) && (PositionDel>Workers.size()))
		{
			cout << "Invalid position!";
		}
		else
		{
			
			Workers::iterator  it = (Workers.begin() + PositionDel - 1);
			  Workers.erase(it);
			//   delete *it;
			
			  /*
			for ( auto it = Workers.begin(); it != Workers.end();)
			{
				IWorker *b = *it;
				if (b->GetPosition() == PositionDel)
				{
					it = Workers.erase(it);
					delete b;
				}
				else it++;

			}*/
			
			/*	//лямбда функция видалення
			Workers.erase(remove_if(begin(Workers), end(Workers),
			[PositionDel](Worker*  obj)
			{
			return ((obj->GetPosition() == PositionDel));
			}),
			end(Workers));


			*/

			int i = 1;
			for (auto &worker : Workers)
			{
				worker->SetPosition(i);
				i++;
			}

			cout << "Workers in position  " << PositionDel << " deleted!" << endl;
		}
	}
	else
	{
		cout << "No workers!";
	}
}
void Department::Print()
{
	if (Workers.empty())
	{
		cout << "No workers!";
		_getch();
	}
	else
	{
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << "|  Position   |   ID     |    Name   |   Salary  | Type worker  |   Tarif/Hours  |   Bonus/PayHour  |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		for (auto &Worker : Workers)
		{
			Worker->Print();
		}
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
	}

}

void  Department::Info()
{
	cout << "INFO ABOUT WORKERS" << endl;
	cout << "Count workers in firm: " << Worker::GetCount() << endl;
	cout << "Count workers, who has worked in firm : " << Worker::GetMaxID() << endl;
}

Department::Department()
{
	this->ActiveM = 0;	
	this->CountItemMenu = 6;
	this->flagMenu = true;
	this->flagEnd = true;
}


Department::~Department()
{
	for (auto it = Workers.begin(); it != Workers.end(); ++it)
	{
		delete *it;
	}
	Workers.clear();

}

int Worker::_counter = 0;
int Worker::_counterID = 0;


int main()
{
	Department Renome;
	Renome.Menu();


	return 0;

}