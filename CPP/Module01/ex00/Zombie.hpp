#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

	public:
		std::string	name;
		void	Announce(void);
		void	Destroy(Zombie *zombie);
} ;

void	Zombie::Announce(void) {
		std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::Destroy (Zombie *zombie) {
	delete zombie;
}

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif