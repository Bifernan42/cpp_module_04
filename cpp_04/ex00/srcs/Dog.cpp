#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog") {std::cout << "Dog : default constructor called\n";}

Dog::Dog(std::string type) : Animal(type) {std::cout << "Dog : constructor called\n";}

Dog::Dog(const Dog & other)
{
	std::cout << "Dog : copy constructor called\n";
	type_ = other.type_;
}

Dog & Dog::operator=(const Dog & other)
{
	if (this != &other)
		this->type_ = other.type_;
	return (*this);
}	

Dog::~Dog()
{
	std::cout << "Dog : destructor called\n";
}

void	Dog::makeSound() const
{
	std::cout << "Dog : *woof*\n";
}
