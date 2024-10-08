#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat") {std::cout << "Cat : default constructor called\n";}

Cat::Cat(std::string type) : Animal(type) {std::cout << "Cat : constructor called\n";}

Cat::Cat(const Cat & other)
{
	std::cout << "Cat : copy constructor called\n";
	type_ = other.type_;
}

Cat & Cat::operator=(const Cat & other)
{
	if (this != &other)
		this->type_ = other.type_;
	return (*this);
}	

Cat::~Cat()
{
	std::cout << "Cat : destructor called\n";
}

void	Cat::makeSound() const
{
	std::cout << "Cat : *meow*\n";
}
