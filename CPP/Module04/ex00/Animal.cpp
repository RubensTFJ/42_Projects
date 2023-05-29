/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:40:36 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/29 14:56:44 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Animal {
	protected:
		std::string	type;

	public:
		Animal();
		Animal(std::string type);
		~Animal();
		std::string		getType() const;
		virtual void	makeSound(void) const;
} ;

Animal::Animal()
{}

Animal::~Animal()
{}

Animal::Animal(std::string type):
	type(type)
{}

void	Animal::makeSound(void) const  {
	std::cout << "Grrr." << std::endl;
}

std::string Animal::getType() const  {
	return (type);
}

////////////////////////////////////////////////////////////////////////////

class Dog: public Animal {
	public:
		Dog();
		~Dog();
		virtual void	makeSound(void) const override;
} ;

Dog::Dog():
	Animal("Dog")
{}

Dog::~Dog()
{}

void	Dog::makeSound(void) const  {
	std::cout << "Bark." << std::endl;
}

////////////////////////////////////////////////////////////////////////////

class Cat: public Animal{
	public:
		Cat();
		Cat(std::string type);
		~Cat();
		virtual void	makeSound(void) const override;
} ;

Cat::Cat():
	Animal("Cat")
{}

Cat::~Cat()
{}

void	Cat::makeSound(void) const  {
	std::cout << "Meow." << std::endl;
}

////////////////////////////////////////////////////////////////////////////

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	return 0;
}