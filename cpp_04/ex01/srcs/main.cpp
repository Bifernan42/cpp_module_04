#include "../includes/WrongCat.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include <iostream>


//compile time vs runtime


int	main(void)
{
    std::cout << "First Test with allocated Annimals...\n";
    Animal *ranimal_1 = new Animal("random animal");
    *ranimal_1 = Cat();
    Animal *ranimal_2 = new Animal("random animal");
    *ranimal_2 = Cat();
    ranimal_1->makeSound();
    ranimal_2->makeSound();
    delete ranimal_1;
    delete ranimal_2;

    std::cout << "\nSecond Mandatory Test With an array of Animals...\n";
    Animal animalArray[2];
    animalArray[0] = Dog();
    std::cout << "First Animal in the array = " << animalArray[0].getType() << std::endl;
    animalArray[0].makeSound();
    animalArray[1] = Cat();
    std::cout << "Second Animal in the array = " << animalArray[1].getType() << std::endl;
    animalArray[1].makeSound();

    std::cout << "\nThird Part : Additionnal Tests...\n";

   std::cout << "\nInstanciating 3 cats by 3 different means and giving them Ideas\n";
   Cat cat_1 = Cat();
   Cat cat_2(cat_1);
   Cat cat_3 = cat_2;

   cat_1.add_idea("* I WANT FISH *");
   cat_2.add_idea("* I WANT CAT *");
   cat_3.add_idea("* I WANT BRAIN *");

   cat_1.show_ideas();
   cat_2.show_ideas();
   cat_3.show_ideas();

   std::cout << "\n We are now assigning cat_2 to cat_1 and cat_1 to cat_3, thereby freeing the brains & allocating new ones...\n";
   cat_1 = cat_2;
   cat_1.show_ideas();
   cat_3 = cat_1;
   cat_3.show_ideas();


   std::cout << "\nInstanciating cat_4 with cat_3 should call copy constructor and give cat_4 the same Ideas as cat_3\n";
   Cat cat_4(cat_3);
   cat_4.add_idea("I WANT HOTDOG");
   cat_4.add_idea("I WANT $$$");
   cat_4.show_ideas();
	return (0);
}
