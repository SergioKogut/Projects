/*

#include<iostream>
#include"conio.h"
#include <Windows.h>
#include <vector>
#include <array>
#include <iomanip>
#include <locale>
#include <stack>

using namespace std;

enum state { EMPTY, GRASS, RABBIT, FOX }; //  відсутнє життя, трава,кролик,лисиця 
const int FOX_LIFE = 5;
const int RABBIT_LIFE = 5;
const int COLUMNS = 14;
const int ROWS = 9;

class Life
{
public:
	Life() {};
	Life(int x, int y) :_x(x), _y(y) {};
	~Life() {};
	virtual state WhoIsYou() = 0;
	virtual void Print() = 0;
	virtual int GetAge() = 0;

	void 	SetTextColor(string text, int color)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		cout << text;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	};
protected:
	//координати
	int _x;
	int _y;

};

class Empty : public Life
{
public:
	Empty() {};
	Empty(int x, int y) :Life(x, y) {};
	~Empty() {};
	state WhoIsYou()
	{
		return state::EMPTY;
	};
	void Print()
	{
		if (_x == 0 || _y == 0 || _x == 8 || _y == 13)
		{
			cout << "#";
		}
		else
		{
			cout << " ";
		}

	}
	int GetAge()
	{
		return  1;
	}
};

class Fox : public Life
{
public:
	Fox() {};
	Fox(int x, int y, int age) :Life(x, y), _age(age) {};
	~Fox() {};
	state WhoIsYou()
	{
		return state::FOX;
	};
	void Print()
	{
		SetTextColor("F", 12);
	}
	int GetAge()
	{
		return _age;
	}

private:
	int _age;
};

class Rabbit : public Life
{
public:
	Rabbit() {};
	Rabbit(int x, int y, int age) :Life(x, y), _age(age) {};
	~Rabbit() {};
	state WhoIsYou()
	{
		return state::RABBIT;
	};
	void Print()
	{
		SetTextColor("R", 11);
	}
	int GetAge()
	{
		return _age;
	}

private:
	int _age;

};

class Grass : public Life
{
public:
	Grass() {};
	Grass(int x, int y) :Life(x, y) {};
	~Grass() {};
	state WhoIsYou()
	{
		return state::GRASS;
	};
	void Print()
	{
		SetTextColor("G", 10);


	}
	int GetAge()
	{
		return  1;
	}
};

class World
{
public:
	World() :СountLife(10), СurrentLife(0)
	{};
	~World() {};
	void Run()
	{
		//AddWorld();
		GenerateWorld();

		cout << "Введіть кількість циклів життя:";
		cin >> СountLife;

		for (int i = 0; i < СountLife; i++)
		{
			PrintWorld();
			NextStep();
			UpdateWorld();
			_getch();
		}
	};



private:
	vector<vector<Life*>> field; // поле з тваринами і рослинами
	vector<vector<Life*>> field_temp; // тимчасове робоче поле
	vector<int> sums; // містить сусідів клітини
	int СountLife; // кількість циклів життя
	int СurrentLife;
	void PrintWorld()
	{
		system("cls");
		cout << "\n\n\n\n\n";
		cout << "Поточний цикл: " << СurrentLife << endl;
		for (int i = 0; i < field.size(); i++)
		{
			cout << "\t\t\t";
			for (int j = 0; j < field[i].size(); j++)
			{
				field[i][j]->Print();
			}
			cout << endl;
		}
	};

	void FindNeighbors(int x, int y)
	{
		sums.resize(4);
		sums[EMPTY] = 0;
		sums[GRASS] = 0;
		sums[RABBIT] = 0;
		sums[FOX] = 0;
		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (!(i == x) || !(j == y))
				{
					sums[field[i][j]->WhoIsYou()]++;
				}
			}
		}


	}

	void NextStep()
	{
		//встановлюємо розміри темпового поля відносно основного поля
		field_temp.resize(field.size());
		for (int j = 0; j < field.size(); j++)
		{
			field_temp[j].resize(field[j].size());
		}

		for (int i = 0; i < field_temp.size(); i++)
		{
			for (int j = 0; j < field_temp[i].size(); j++)
			{
				field_temp[i][j] = new Empty(i, j);
			}
		}




		// пошук сусідів клітини
		for (int i = 1; i < field.size() - 1; i++)
		{
			for (int j = 1; j < field[i].size() - 1; j++)
			{
				// пошук сусідів заданої клітини

				FindNeighbors(i, j);

				// заповнення тимчасового поля тваринами наступної генерації
				
				
				// умови створення  життя

				if (field[i][j]->WhoIsYou() == EMPTY)
				{
					if ((sums[FOX]>1) && (sums[RABBIT]>=1))
					{
						field_temp[i][j] = new Fox(i, j, 0);
					}
					else if ((sums[RABBIT]>1) && (sums[GRASS]>=1))
					{
						field_temp[i][j] = new Rabbit(i, j, 0);
					}
					else if (sums[GRASS]>=1)
					{
						field_temp[i][j] = new Grass(i, j);
					}
					else
					{
						field_temp[i][j] = new Empty(i, j);
					}
				}

				// умови виживання лиса

				if (field[i][j]->WhoIsYou() == FOX)
				{
					if (sums[RABBIT]==0)
					{
						field_temp[i][j] = new Empty(i, j);
					}
					else if (sums[FOX]>5)
					{
						field_temp[i][j] = new Empty(i, j);
					}
					else if (field[i][j]->GetAge()>FOX_LIFE)
					{
						field_temp[i][j] = new Empty(i, j);
					}
					else
					{
						field_temp[i][j] = new Fox(i, j, field[i][j]->GetAge() + 1);
					}





				}

				// умови виживання кролика

				if (field[i][j]->WhoIsYou() == RABBIT)
				{
					if (sums[GRASS] == 0)
					{
						field_temp[i][j] = new Empty(i, j);
					}
					else if (sums[FOX] >= sums[RABBIT])
					{
						field_temp[i][j] = new Empty(i, j);
					}
					else if (field[i][j]->GetAge()>RABBIT_LIFE)
					{
						field_temp[i][j] = new Empty(i, j);
					}
					else
					{
						field_temp[i][j] = new Rabbit(i, j, field[i][j]->GetAge() + 1);
					}
				}

				// умови виживання трави

				if (field[i][j]->WhoIsYou() == GRASS)
				{
					if ((sums[RABBIT] > 1) && (sums[GRASS] > 1))
					{
						field_temp[i][j] = new Rabbit(i, j, 0);
					}
					else if (sums[GRASS]>sums[RABBIT])
					{
						field_temp[i][j] = new Grass(i, j);
					}
					else
					{
						field_temp[i][j] = new Empty(i, j);
					}

				}


			}

		}
	}

	void UpdateWorld()
	{




		for (int i = 0; i < field.size(); i++)
		{

			for (int j = 0; j < field[i].size(); j++)
			{

				//замінюємо елементи поля на елементи тимчасового поля
				field[i][j] = field_temp[i][j];
				//field_temp[i][j] = NULL;
			}

			// збільшуємо лічильник циклів


		}

		СurrentLife++;


	};
	//додаєм поле з тваринами
	void AddWorld()
	{
	/*	const char* field1[] =
		{
			"##############",
			"#            #",
			"#     FF     #",
			"#    GGRR    #",
			"#    GGFF    #",
			"#   GGGRR    #",
			"#   GGGF     #",
			"#    RRF     #",
			"##############",
		};

		const char* field1[] =
		{
		"##############",
		"#     RRR    #",
		"#     GRG    #",
		"#     GRG    #",
		"#      FF    #",
		"#            #",
		"#            #",
		"#            #",
		"##############",
		};
		 

		field.resize((sizeof(field1) / sizeof(char*)));

		for (int i = 0; i < field.size(); i++)
		{
			size_t length = strlen(field1[i]);
			field[i].resize(length);

			for (int j = 0; j < length; j++)
			{
				if (field1[i][j] == 'G')
				{
					field[i][j] = new Grass(i, j);
				}
				else if (field1[i][j] == 'R')
				{
					field[i][j] = new Rabbit(i, j, 0);
				}
				else if (field1[i][j] == 'F')
				{
					field[i][j] = new Fox(i, j, 0);
				}
				else
				{
					field[i][j] = new Empty(i, j);
				}

			}


		}




	};

	void InitWorld() {};
	void GenerateWorld()
	{
	
		field.resize(ROWS);
		for (int j = 0; j < field.size(); j++)
		{
			field[j].resize(COLUMNS);
		}

		for (int i = 0; i < field.size(); i++)
		{
			for (int j = 0; j < field[i].size(); j++)
			{
				field[i][j] = new Empty(i, j);
			}
		}



		for (int i = 1; i < field .size()-1; i++)
		{
			for (int j = 1; j < field [i].size()-1; j++)
			{
				int z = rand() % 4 + 1;

				switch (z)
				{
				case 1:
					{
					field[i][j] = new Empty(i, j);
					break;
					}
				case 2:
				{
					field[i][j] = new Fox(i, j, 0);
					break;
				}
				case 3:
				{
					field[i][j] = new Rabbit(i, j, 0);
					break;
				}
				case 4:
				{
					field[i][j] = new Grass(i, j);
					break;
				}


				default:
					break;
				}

					
			}
				

		}
		 
	
	
	
	
	
	
	
	
	};
	void DeleteWorld() {};

};


int main()
{
	srand(time(NULL));
	SetConsoleCP(1251); // українська мова
	SetConsoleOutputCP(1251); //  українська мова
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	World World1;
	World1.Run();
};

*/