
#include <iostream>
#include "Tom.h"

Tom::Tom(std::string name) : name(name)
{
	std::cout << "Tom constructed " << name << "\n";

}
void Tom::goFootball()
{
	std::cout << name << " is invited foolball\n";
}