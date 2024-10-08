#include "../includes/WrongCat.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include <iostream>


//compile time vs runtime


int	main(void)
{

    std::cout << "We've now made the Animal class an Abstract class by defining the makeSound() as pure virtual\n";


    std::cout << "it's not possible anymore to instanciate an Animal\n";

    //Animal new_animal();

    std::cout << "But it's still possible to instanciate derived classes :\n";
    Cat new_cat;
    new_cat.makeSound();
/*
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
   cat_4.show_ideas();*/
	return (0);
}
