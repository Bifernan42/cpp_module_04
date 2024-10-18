#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
	protected:
		std::string type_;
	public:
		Animal();
		Animal(std::string);
		Animal(const Animal &);
		Animal & operator=(const Animal &);
		//making the Animal destructor virtual ensures polymorphism to work properly by allowing the right chaining in destructor calls
		virtual ~Animal();
		virtual void makeSound() const = 0;
		std::string getType(void) const;
};

#endif
