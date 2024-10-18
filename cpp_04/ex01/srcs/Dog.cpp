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
	delete brain_;
	std::cout << "Dog : destructor called\n";
}

void	Dog::makeSound() const
{
	std::cout << "Dog : *woof*\n";
}

void Dog::remove_idea()
{
    this->brain_->remove_idea();
}


void Dog::add_idea(const std::string &new_idea)
{
    this->brain_->add_idea(new_idea);
}

void Dog::show_ideas() const
{
    this->brain_->express_ideas();
}
