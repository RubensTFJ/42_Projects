#include "Zombie.hpp"

using namespace std;

void	Zombie::Announce(void) {
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::Destroy (Zombie *zombie) {
	delete zombie;
}

