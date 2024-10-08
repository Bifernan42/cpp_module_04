#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog"), brain_(new Brain) {std::cout << "Dog : default constructor called\n";}

//Dog::Dog(std::string type) : Animal(type), brain_(new Brain) {std::cout << "Dog : constructor called\n";}

Dog::Dog(const Dog & other)
{
	std::cout << "Dog : copy constructor called\n";
	brain_ = new Brain(*other.brain_);
	type_ = other.type_;
}
//deep copy so two dawgs don't share one brain
Dog & Dog::operator=(const Dog & other)
{
    std::cout << "Dog : copy assignment operator overload called\n";
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain_;
		this->brain_ = new Brain(*other.brain_);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog : destructor called\n";
	delete brain_;
}

void	Dog::makeSound() const
{
	std::cout << "Dog : *woof*\n";
}
