#include <iostream>
#include <map>

class Harls {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		std::map<std::string, void(*)(void)> functions;

	public:
		Harls();
		~Harls();
		void complain(std::string level);
} ;

void	debug(void){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	info(void){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put \
		enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	warning(void){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for \
		years whereas you started working here since last month." << std::endl;
}

void	error(void){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harls::Harls() :
	functions({
		{"DEBUG", &Harls::debug},
		{"INFO", &Harls::info},
		{"WARNING", &Harls::warning},
		{"ERROR", &Harls::error}
	})
{

}

void	Harls::complain(std::string level){
	functions[level]();
}
