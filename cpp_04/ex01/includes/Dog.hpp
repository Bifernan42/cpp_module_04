#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain_;
	public:
		Dog();
		Dog(const Dog &);
		Dog & operator=(const Dog &);
		~Dog();
		void makeSound() const;
		void remove_idea();
		void add_idea(const std::string &);
		void show_ideas() const;
};

#endif
