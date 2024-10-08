#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat"), brain_(new Brain) {std::cout << "Cat : default constructor called\n";}

//Cat::Cat(std::string type) : Animal(type), brain_(new Brain) {std::cout << "Cat : constructor called\n";}

Cat::Cat(const Cat & other)
{
	std::cout << "Cat : copy constructor called\n";
	brain_ = new Brain(*other.brain_);
	type_ = other.type_;
}

Cat & Cat::operator=(const Cat & other)
{
	std::cout << "Cat : copy assignment operator overload called\n";
    if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain_;
		this->brain_ = new Brain(*other.brain_);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat : destructor called\n";
	delete brain_;
}

void	Cat::makeSound() const
{
	std::cout << "Cat : *meow*\n";
}

void Cat::add_idea(const std::string &new_idea)
{
    this->brain_->add_idea(new_idea);
}

void Cat::show_ideas() const
{
    this->brain_->express_ideas();
}
