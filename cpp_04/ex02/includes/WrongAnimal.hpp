#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
	protected:
		std::string type_;
	public:
		WrongAnimal();
		WrongAnimal(std::string);
		WrongAnimal(const WrongAnimal &);
		WrongAnimal & operator=(const WrongAnimal &);
		~WrongAnimal();
		void makeSound() const;
		std::string getType(void) const;
};

#endif
