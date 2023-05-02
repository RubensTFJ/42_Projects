#include "Zombie.hpp"
# include <iostream>
# include <cstring>
void randomChump(std::string name)
{
	Zombie	zombie;

	zombie.name = name;
	zombie.Announce();
}