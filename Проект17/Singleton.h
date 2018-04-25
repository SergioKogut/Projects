#pragma once
#include <string>
using std::string;

class Singleton
{
public:
	
	static Ted* getTedInstance(string name);
	static Tom* getTomInstance(string name);

	~Singleton()
	{
		delete TedInstance;
		delete TomInstance;
	};

private:

	static Ted* TedInstance;
	static Tom* TomInstance;


};