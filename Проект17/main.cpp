#include <iostream>
#include <string>
#include"Ted.h"
#include"Tom.h"
#include"Singleton.h"

Tom * Singleton::TomInstance = nullptr;
Ted * Singleton::TedInstance = nullptr;

using namespace std;

int main()
{
	cout << "main:\n";
	Ted* Ted1 = Singleton::getTedInstance("Ted1");
	
	 
	return 0;
}
