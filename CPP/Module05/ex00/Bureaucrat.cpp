
#include <iostream>

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat(const std::string name);
		~Bureaucrat();
		int					getGrade(void);
		const std::string	getName(void);
}


Bureaucrat::Bureaucrat(const std::string name):
	grade(150), name(name)
{}

Bureaucrat::~Bureaucrat()
{}

const std::string	Bureaucrat::getName(void) {
	return (this->name);
}
int	Bureaucrat::getGrade(void) {
	return (this->grade);
}




// a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException