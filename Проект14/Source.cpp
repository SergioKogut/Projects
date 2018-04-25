#include<iostream>
#include<string>
#include<vector>
#include"conio.h"
#include <Windows.h>
#include <iomanip>
#include <algorithm>
#include <list>
#include <array>
#include <algorithm>
#include "io.h"
#include "fcntl.h"
#include <ctime>


#define BLACK 8
#define RED 12

using namespace std;

enum rank { SIX = 6, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
enum suit { CLUBS = 0, DIAMONDS, HEARTS, SPADES };


void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void SetTextColor(int color, string text)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << text << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

class Card
{
public:

	Card();
	Card(int r, int s);
	~Card();


	int GetValue() const;

	friend ostream& operator<<(ostream& os, const Card& aCard);

private:
	int _Rank;
	int _Suit;

};

int Card::GetValue() const
{
	return _Rank;
}

ostream &operator <<(ostream &out, const Card& aCard)
{
	const string RANKS[] = { "6", "7", "8", "9",
		"10", "J", "Q", "K", "A" };
	const string SUITS[] = { "\u2663", "\u2666", "\u2665", "\u2660" };

	if (aCard._Suit == DIAMONDS || aCard._Suit == HEARTS)
	{
		SetColor(RED);
		cout << RANKS[aCard._Rank - 6];
		_setmode(_fileno(stdout), _O_U16TEXT);
		if (aCard._Suit == DIAMONDS) std::wcout << L"\u2666";
		else std::wcout << L"\u2665";
		_setmode(_fileno(stdout), _O_TEXT);

	}

	else if (aCard._Suit == CLUBS || aCard._Suit == SPADES)
	{
		SetColor(BLACK);
		cout << RANKS[aCard._Rank - 6];
		_setmode(_fileno(stdout), _O_U16TEXT);
		if (aCard._Suit == CLUBS) std::wcout << L"\u2663";
		else std::wcout << L"\u2660";
		_setmode(_fileno(stdout), _O_TEXT);

	}

	SetColor(14);


	return out;



}

Card::Card(int r, int s) : _Rank(r), _Suit(s)
{
}

Card::Card()
{
}

Card::~Card()
{
}


class Player
{
public:
	Player();
	Player(string  name);
	~Player();

	static int counter;
	int GetPlayerValue() const;
	Card* GetLastCard();
	string GetName() const;
	void SetName(string name);
	void Add(Card* pCard);
	friend ostream &operator <<(ostream &out,  Player& Player);
private:
	string _name;
	vector <Card*> PlayerCards;
	int _PlayerValue;
};

Card*  Player::GetLastCard()
{
	return  PlayerCards.pop_back;
}

ostream &operator <<(ostream &out, Player& Player)
{
	out << Player._name << ": Score" << Player.GetPlayerValue() << Player.GetLastCard();
	return out;

}
void Player::SetName(string name)
{
	this->_name = name;
}

string Player::GetName() const
{
	return _name;
}


void Player::Add(Card* pCard)
{
	PlayerCards.push_back(pCard);

}


int Player::GetPlayerValue() const
{
	return _PlayerValue;
}
Player::Player()
{
	counter++;
	this->_name = "Player " + to_string(counter);
	this->_PlayerValue = 0;
}

Player::Player(string  name)
{
	counter++;
	this->_name = name + to_string(counter);
	this->_PlayerValue = 0;
}

Player::~Player()
{
}




class Deck
{
public:
	Deck();
	~Deck();
	void Print() const;
	void Create();
	void Deal(Player& player);


private:
	vector <Card*> Cards;
	int CountCards;

};

void Deck::Deal(Player& player)
{
	for (int  i = 0; i < CountCards/2; i++)
	{
		player.Add(Cards.pop_back);
	}
}
void Deck::Print() const
{
	int i = 1;
	for (auto &card : Cards)
	{
		cout << *card;
		if (i % 9 == 0) cout << endl;
		i++;
	}

}
void Deck::Create()
{
	//створюЇмо карти

	for (int s = CLUBS; s <= SPADES; ++s)
	{
		for (int r = SIX; r <= ACE; ++r)
		{
			Cards.push_back(new Card(r, s));

		}
	}

	random_shuffle(Cards.begin(), Cards.end());

}
Deck::Deck()
{
	CountCards = 36;
	Create();

}
Deck::~Deck()
{

	for (int i = 0; i < Cards.size(); ++i)
	{
		delete Cards[i];
	}

}


class Game
{
public:
	Game();
	Game(const string names[]);
	~Game();
	void Play();

private:
	Player Player1, Player2;
	Deck Cards;
	int _CountPlayer;
};

void Game::Play()
{
	//// роздаЇмо карти гравц€м
	Cards.Deal(Player1);
	Cards.Deal(Player2);


}

Game::Game()
{
}
Game::Game(const string names[])
{
	_CountPlayer = 2;
	Player1.SetName(names[0]);
	Player1.SetName(names[1]);
}


Game::~Game()
{
}







int Player::counter = 0;

int main()
{

	Deck Deck1;

	Deck1.Print();

	
	SetColor(14); // задаЇм кол≥р
	string PlayerName[2];
	
	cout << "\t\t\tWelcome to WinoCard !!!\n\n\n\n" << endl;
	cout << "Enter first player name: ";
	cin >> PlayerName[0];
	cout << "Enter second player name: ";
	cin >> PlayerName[1];
	
	
	system("cls");
	cout << "\n\n\n";

	Game aGame(PlayerName);
	aGame.Play();




	return 0;
}
