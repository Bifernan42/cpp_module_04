#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {std::cout << "WrongCat : default constructor called\n";}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {std::cout << "WrongCat : constructor called\n";}

WrongCat::WrongCat(const WrongCat & other)
{
	std::cout << "WrongCat : copy constructor called\n";
	type_ = other.type_;
}

WrongCat & WrongCat::operator=(const WrongCat & other)
{
	if (this != &other)
		this->type_ = other.type_;
	return (*this);
}	

WrongCat::~WrongCat()
{
	std::cout << "WrongCat : destructor called\n";
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat : *meow*\n";
}
