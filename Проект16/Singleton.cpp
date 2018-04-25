#include<iostream>
#include<string>

using namespace std;

class Singleton
{
public:
	void SetName(string name);
	string GetName() const ;
	static Singleton* getInstance(string name);
	 
	~Singleton() 
	{
		delete instance;
	};

private:
	Singleton();
	Singleton(string name);
	static Singleton* instance;

	string _name;
	
};
void Singleton::SetName(string name)
{
	this->_name = name;
}
string Singleton::GetName() const
{
	return _name;
}
Singleton* Singleton::getInstance(string name = "noname")
{
	if (instance == 0)
	{
		instance = new Singleton();
		instance->SetName(name);
	}
	return instance;
};
Singleton::Singleton()
{
	this->_name = "noname";
};
Singleton::Singleton(string name)
{
	this->_name = name;
};

Singleton* Singleton::instance =nullptr;


void main()
{

	Singleton* S1 = Singleton::getInstance();
	Singleton* S2 = Singleton::getInstance("Two");
	
	cout << S1->GetName()<<endl;


}




