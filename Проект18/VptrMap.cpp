#include<iostream>
#include<vector>
#include<map>
#include<string>


using namespace std;

int Add(int, int);
int Sub(int, int);
int Div(int, int);
int Mult(int, int);

class menu
{
public:
	menu();// по замовчуванню
	menu(map<string, int(*)(int, int)>MapPtrFunc2);// параметризований
	menu(pair<string, int(*)(int, int)>);// параметризований
	~menu();
	void Show();


private:
	map<string, int(*)(int, int)>MapPtrFunc1;
	int a = 4;
	int b = 3;
};
void  menu::Show()
{
	for (auto it = MapPtrFunc1.begin(); it != MapPtrFunc1.end(); ++it)
	{
		cout << it->first << ":  " << it->second(a, b) << endl;
	}


}

menu::menu()
{
	MapPtrFunc1 = { { "Add", Add }, { "Sub", Sub }, { "Mult", Mult }, { "Div", Div } };

}

menu::menu(map<string, int(*)(int, int)>MapPtrFunc2)
{
	MapPtrFunc1 = MapPtrFunc2;

}

menu::menu(pair<string, int(*)(int, int)>a)
{
	MapPtrFunc1.insert(a);
}

menu::~menu()
{
}


class Game
{
public:
	void Run();
	int Add1(int, int);
	Game();
	~Game();

private:
//	pair<string, int(*)(int, int)> para = {"Add",Add1 };
	menu Menu1({ "Add1",Add1 });

};
int Game::Add1(int, int) 
{
	return 5;
}

void Game::Run()
{



}

Game::Game()
{
}

Game::~Game()
{
}


double area(double R)
{
	const double PI = 3.1415;
	return PI * R * R;
}

int Add(int a,int b)
{
	return a + b;
}
int Mult(int a, int b)
{
	return a * b;
}

int Div(int a, int b)
{
	return a / b;
}

int Sub(int a, int b)
{
	return a - b;
}


void one()
{
	cout << "Funk one" << endl;
}

void two()
{
	cout << "Funk two" << endl;
}

int main()
{
	
	void(*FunkPtr)();

	
	FunkPtr = &two;
	FunkPtr();
	FunkPtr = &one;
	FunkPtr();

	//---------------------------------------------------------------------------------

	double(*pfunc)(double);    // переменная указатель на функцию
	pfunc = area;

	double r = 1.0;
	cout << "for circle radius " << r << " Area = "
		<< (*pfunc)(r) << endl;

	
	
	int(*CalcPtr)(int, int);
	int a;
	int b;
	cout << "Enter a:";
	cin >> a;
	cout << "Enter b:";
	cin >> b;

	CalcPtr=Mult;
	cout << a << "*" << b << " = " << CalcPtr(a, b) << endl;

	//------------------------vector-----------------------------------------------------

	vector<int(*)(int, int)> VPtrFunc;
	
	VPtrFunc.push_back(Add);
	VPtrFunc.push_back(Sub);
	VPtrFunc.push_back(Mult);
	VPtrFunc.push_back(Div);

	cout << a << "*" << b << " = " << VPtrFunc[2](a, b) << endl;

	//------------------------------map---------------------------------------------------
	map<string, int(*)(int, int)>MapPtrFunc = { { "Add", Add },{ "Sub", Sub },{ "Mult", Mult},{ "Div", Div } };

	for (auto it = MapPtrFunc.begin(); it != MapPtrFunc.end(); ++it)
	{
		cout << it->first << ":  " << it->second(a, b) << endl;
	}

	//--------------------class-----------------------------------------------------

	

	cout << "Menu:" << endl;
	//menu Menu1;
	//menu Menu1(MapPtrFunc);
	menu Menu1( {"Add", Add });
	
	Menu1.Show();




	return 0;
}