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
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType(void) const;
};

#endif
