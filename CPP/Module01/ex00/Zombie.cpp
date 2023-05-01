#include "Zombie.hpp"

using namespace std;

class Zombie {
	std::string	name;

	public:
		void	Zombie::Announce(void) {
			std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
	}

		void	Zombie::Destroy (Zombie *zombie) {
			delete zombie;
	}
} ;
