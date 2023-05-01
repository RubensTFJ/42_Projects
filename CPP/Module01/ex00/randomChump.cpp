#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie	zombie;

	zombie.name = name;
	zombie.Announce();
}