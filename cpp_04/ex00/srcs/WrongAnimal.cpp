#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("no_type") {std::cout << "WrongAnimal : default constructor called\n";}

WrongAnimal::WrongAnimal(std::string type) : type_(type) {std::cout << "WrongAnimal : constructor called\n";}

WrongAnimal::WrongAnimal(const WrongAnimal & other)
{
	std::cout << "WrongAnimal : copy constructor called\n";
	type_ = other.type_;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & other)
{
	if (this != &other)
		this->type_ = other.type_;
	return (*this);
}	

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal : destructor called\n";
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal : *indistinguishable sound*\n";
}

std::string WrongAnimal::getType(void) const
{
	return (type_);
}
