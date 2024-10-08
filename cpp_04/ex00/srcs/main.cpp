#include "../includes/WrongCat.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"


//compile time vs runtime


int	main(void)
{
	std::cout << "\nMandatory Test...\n ";

    const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "\n By using the virtual keyword in function definition we allow polymorphism\n";
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;


	std::cout << "\nSecond Part with WrongAnimals...\n ";

	std::cout << "\n Without the keyword virtual, reference to member functions are processed during compile time and not runtime so we are not getting the overloaded functions like before\n";
	const WrongAnimal* meta_2 = new WrongAnimal();
	const WrongAnimal* i_2 = new WrongCat();
	std::cout << i_2->getType() << " " << std::endl;
	i_2->makeSound(); //will output the animal sound!
	meta_2->makeSound();

	delete meta_2;
	delete i_2;
	return (0);
}
