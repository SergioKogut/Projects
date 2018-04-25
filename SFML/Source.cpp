#include<SFML/Graphics.hpp>
#include<string>
#include<array>
#include<vector>
#include<locale>
#include <Windows.h>
#include"conio.h"

using namespace sf; 
using namespace std;

int ground = 537;

float offsetX = 0, offsetY = 0;
const int H = 10;
const int W = 20;



String TileMap[H] = {
	"AAAAAAAAAA AAAAAAAAAA",
	"0                  0",
	"0                  0",
	"0     0000  B  B   0",
	"0           B  B   0",
	"0000        B  B   0",
	"0           00000000",
	"000      000       0",
	"000000             0",
	"DDDDDDDDDDDDDDDDDDDD",
};

class TextMessage
{
public:
	TextMessage();
	TextMessage( string text, int x, int y, int SizeFont, Font font, Color color);
	TextMessage::TextMessage(string text, int x, int y);
	TextMessage(string text);
	~TextMessage();
	void Show(RenderWindow &window);
	void SetColor(Color color);
private:
	Text _textmessage;
	int _x, _y;
	string _text;
	int _sizeFont;
	Font _font;
	Color _color;
};

void TextMessage::Show(RenderWindow &window)
{
	
	window.draw(_textmessage);

}
TextMessage::TextMessage(string text) :_text(text)
{
	_font.loadFromFile("fonts/cambria-bold.ttf");
	_textmessage.setString(_text); //  
	_textmessage.setPosition(50, 50); //
	_textmessage.setFillColor(sf::Color::Red); // 
	_textmessage.setFont(_font); // 
	_sizeFont = 36;
	_textmessage.setCharacterSize(_sizeFont);

}
TextMessage::TextMessage(string text, int x, int y) :_text(text), _x(x), _y(y)
{
	_font.loadFromFile("fonts/cambria-bold.ttf");
	_textmessage.setString(_text); //  
	_textmessage.setPosition(_x, _y); //
	_color = sf::Color::White;
	_textmessage.setFillColor(_color); // 
	_textmessage.setFont(_font); // 
	_sizeFont = 36;
	_textmessage.setCharacterSize(_sizeFont);

}
TextMessage::TextMessage(string text,
						int x, int y,
						int SizeFont,
						Font font,
						Color color) :_text(text), _x(x), _y(y), _sizeFont(SizeFont), _font(), _color(color)
{
	_font.loadFromFile("fonts/cambria-bold.ttf");
	_textmessage.setString(_text); //  
	_textmessage.setPosition(_x, _y); //
	_textmessage.setFillColor(_color); // 
	_textmessage.setFont(_font); // 
	_textmessage.setCharacterSize(_sizeFont);
}

void TextMessage::SetColor(Color color)
{
	_color = color;
	_textmessage.setFillColor(_color);
}

TextMessage::TextMessage() 
{
}

TextMessage::~TextMessage()
{
}





class Menu
{
public:
	Menu();
	Menu(string Arr[], int count, int x, int y);
	~Menu();



	int  Show(RenderWindow &window)
	{

		/*
			char ch1, ch2;

			while (_flag)
			{

				for (int i = 0; i < _Count; i++)
				{
					if (i == _ActiveM)
					{
						MenuItem[i].SetColor(sf::Color::Red);
					}

					else
					{
						MenuItem[i].SetColor(sf::Color::White);
					}
				}

				ch1 = _getch();
				if (ch1 == -32) ch2 = _getch();
				if (ch1 == -32 && ch2 == KEY_ARROW_UP && _ActiveM != 0) --_ActiveM;
				if (ch1 == -32 && ch2 == KEY_ARROW_DOWN && _ActiveM != _Count - 1) ++_ActiveM;
				if (ch1 == KEY_ENTER) {_flag = false;  return _ActiveM; }

			}
		}*/
		while (_flag)
		{
			window.clear(Color(0, 0, 0));

			for (int i = 0; i < _Count; i++)
			{
				if (i == _ActiveM)
				{
					//MenuItem[i]->SetColor(sf::Color::Red);
					MenuItem[i]->Show(window);
				}
				else
				{
					//MenuItem[i]->SetColor(sf::Color::White);
					MenuItem[i]->Show(window);
				}
			}
		
			if (Keyboard::isKeyPressed(Keyboard::Up) && _ActiveM != 0) { --_ActiveM; };
			if (Keyboard::isKeyPressed(Keyboard::Down) && _ActiveM != _Count - 1) { ++_ActiveM; };
			if (Keyboard::isKeyPressed(Keyboard::Space)) { _flag = false;  return _ActiveM; }



			//if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Yellow); MenuNum = 1; }
			//if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Yellow); MenuNum = 2; }
		    //if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Yellow); MenuNum = 3; }

				window.display();
		}
	}
	//--------діалог так ні--------------
	

private:
	vector <TextMessage*> MenuItem;
	int _ActiveM;
	int _Count;
	bool _flag;
	int _x, _y;
	
};



Menu::Menu() : _ActiveM(0), _Count(3), _flag(true)
{
	MenuItem.resize(3);
	
	string temp = "Item";
	_x = 50;
	_y = 50;

	for (int i = 0; i < _Count; i++)
	{
		MenuItem.push_back(new TextMessage(temp + std::to_string(i + 1), _x, _y + i * 40));
	}
	 _ActiveM = 0;
	 _flag = true;

}

Menu::Menu(string Arr[], int count, int x, int y) :_Count(count), _x(x), _y(y)
{
	MenuItem.resize(_Count);
	
	for (int i = 0; i < _Count; i++)
	{
		MenuItem.push_back(new TextMessage(Arr[i], _x, _y + i * 40));
	}
	_ActiveM = 0;
	_flag = true;
}

Menu::~Menu()
{
}



class Player
{
public:

	float dx, dy;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float currentFrame;


	Player::Player(Texture &image)
	{

		sprite.setTexture(image);
		rect = FloatRect(10 * 36, 10 * 36, 36, 40);
		dx = dy = 0;
		currentFrame = 0;
		sprite.setTextureRect(IntRect(300 + 36 * int(currentFrame) + 36, 100, -36, 40));
	}


	void update(float time)
	{
		rect.left += dx*time;
		Collision(0);

		if (!onGround) dy = dy + (float)0.0005*time;
		rect.top += dy*time;
		onGround = false;
		Collision(1);

		if (rect.top > ground) { rect.top = ground; dy = 0; onGround = true; }

		currentFrame += 0.005*time;
		if (currentFrame > 8) currentFrame -= 8;
		if (dx<0) sprite.setTextureRect(IntRect(300 + 36 * int(currentFrame) + 36, 100, -36, 40));
		if (dx>0) sprite.setTextureRect(IntRect(300 + 36 * int(currentFrame), 100, 36, 40));


		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

		dx = 0;
	}

	void Collision(int dir)
	{
		for (int i = rect.top / 64; i < (rect.top + rect.height) / 64; i++)
			for (int j = rect.left / 64; j <(rect.left + rect.width) / 64; j++)
			{
				if (TileMap[i][j] == '0')
				{
					if ((dx > 0) && (dir == 0)) rect.left = j * 64 - rect.width;
					if ((dx < 0) && (dir == 0)) rect.left = j * 64 + 64;
					if ((dy > 0) && (dir == 1)) { rect.top = i * 64 - rect.height; dy = 0; onGround = true; }
					if ((dy < 0) && (dir == 1)) { rect.top = i * 64 + 64; dy = 0; onGround = true; }
				}

				if (TileMap[i][j] == 'B')
				{

					TileMap[i][j] = ' ';

				}




			}
	}



};



int main()
{
	RenderWindow window(VideoMode(1280, 640), "SFML works!");

	string MenuText[3] = { "Start game","About","Exit" };

	Menu start(MenuText, 3, 50, 50);

	
	// Load a sprite to display

	TextMessage One("Life");
	 
	Texture t;
	t.loadFromFile("mario.png");
	Texture t1;
	t1.loadFromFile("Tiles.png");
	float currentFrame = 0;

	Player p(t);
	Clock clock;
	Sprite s;
	//RectangleShape restangle;
	s.setTexture(t1);

	int z = start.Show(window);

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds() / 120;
		clock.restart();

		Event	event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}


		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			p.dx = -0.1;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			p.dx = 0.1;
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (p.onGround) { p.dy = -0.4; p.onGround = false; }

		}
		 
		p.update(time);
		window.clear(Color::White);

		

		if (p.rect.left>640)	offsetX = p.rect.left - 640;

		//if (p.rect.top>500) offsetY = p.rect.top-500;

		// карта з текстурами

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == 'A') s.setTextureRect(IntRect(320, 256, 128, 64));
				if (TileMap[i][j] == '0') s.setTextureRect(IntRect(384, 0, 64, 64));
				if (TileMap[i][j] == 'D') s.setTextureRect(IntRect(128, 192, 64, 64));
				if (TileMap[i][j] == 'B') s.setTextureRect(IntRect(128, 384, 64, 64));
				if (TileMap[i][j] == ' ')  continue;

				if ((i == 0) && (j % 2 == 0) && (j<W))
				{
					s.setPosition(j * 128 - offsetX, i * 64 - offsetY);
				}
				else
				{
					s.setPosition(j * 64 - offsetX, i * 64 - offsetY);
				}
				window.draw(s);

			}
		
		One.Show(window);
		window.draw(p.sprite);
		window.display();

	}

	return 0;
}
