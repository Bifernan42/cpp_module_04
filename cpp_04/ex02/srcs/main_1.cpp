#include "../includes/WrongCat.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"


//compile time vs runtime


int	main(void)
{
    std::cout << "We've now made the Animal class an Abstract class by defining the makeSound() as pure virtual\n";


    std::cout << "it's not possible anymore to instanciate an Animal\n";

    AAnimal new_animal();

    std::cout << "But it's still possible to instanciate derived classes :\n";
    Cat new_cat;
    new_cat.makeSound();
    return 0;
}
