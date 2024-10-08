#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		//WrongCat(std::string);
		WrongCat(const WrongCat &);
		WrongCat & operator=(const WrongCat &);
		~WrongCat();
		void makeSound() const;
};

#endif
