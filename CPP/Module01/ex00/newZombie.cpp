#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie	*zombie = new Zombie;
	zombie->name = name;
	return (zombie);
}