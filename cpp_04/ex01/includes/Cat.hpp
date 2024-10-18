#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain_;
	public:
		Cat();
		Cat(const Cat &);
		Cat & operator=(const Cat &);
		~Cat();
		void makeSound() const;
		void add_idea(const std::string &);
		void show_ideas() const;
		void remove_idea();
};

#endif
