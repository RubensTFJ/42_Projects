#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <cstring>

class Zombie {

	std::string	name;
	public:
		
		void	Announce(void);
		void	Destroy(Zombie *zombie);


} ;

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif