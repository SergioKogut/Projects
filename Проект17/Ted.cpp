#include "Ted.h"
#include "Tom.h"
#include "Singleton.h"

#include <iostream>

Ted::Ted(std::string name) : name(name)
{
	std::cout << "Ted constructed " << name << "\n";
	Tom * tom = Singleton::getTomInstance("Tom1");
	tom->goFootball();
}
