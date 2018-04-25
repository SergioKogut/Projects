#include "Ted.h"
#include "Tom.h"
#include "Singleton.h"
#include <iostream>

using std::string;



Tom* Singleton::getTomInstance(string name = "Tom")
{
	if (TomInstance == nullptr)
	{
		TomInstance = new Tom(name);
	}
	return TomInstance;
};

Ted* Singleton::getTedInstance(string name = "Ted")
{
	if (TedInstance == nullptr)
	{
		TedInstance = new Ted(name);

	}
	return TedInstance;
};
