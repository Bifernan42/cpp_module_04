#include "../includes/Animal.hpp"

Animal::Animal() : type_("no_type") {std::cout << "Animal : default constructor called\n";}

Animal::Animal(std::string type) : type_(type) {std::cout << "Animal : constructor called\n";}

Animal::Animal(const Animal & other)
{
	std::cout << "Animal : copy constructor called\n";
	type_ = other.type_;
}

Animal & Animal::operator=(const Animal & other)
{
	if (this != &other)
		this->type_ = other.type_;
	return (*this);
}	

Animal::~Animal()
{
	std::cout << "Animal : destructor called\n";
}

void	Animal::makeSound() const
{
	std::cout << "Animal : *indistinguishable sound*\n";
}

std::string Animal::getType(void) const
{
	return (type_);
}
