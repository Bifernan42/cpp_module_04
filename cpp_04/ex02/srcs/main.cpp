#include "../includes/WrongCat.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include <iostream>


//compile time vs runtime
void test(const std::string &testmsg)
{
    static int i;
    std::cout << "\n\033[34m #TEST [" << i << "] : " << testmsg << "\033[0m\n";
    i++;
}

void testOk(bool value)
{
    if (value)
        std::cout << "\033[32m[OK]\033[0m\n";
    else
        std::cout << "\033[31m[KO]\033[0m\n";
}

void cmsg(const std::string &msg)
{
    std::cout << std::endl << "\033[33m[INFO]: " << msg << "\033[0m" << std::endl;
}

int	main(void)
{
    test("Mandatory : memory leaks");
    test("Looking for leaks By allocating & freeing 2 more animals using pointers :");
    Animal *c = new Cat;
    Animal *d = new Dog;
    cmsg("Deleting c & d :");
    delete c;
    delete d;
    testOk(1);
    test("Mandatory Test With an array of Animals*...");
    Animal *animalArray[2];
    cmsg("We declare an array of Animal * (pointers) to avoid object slicing.\nObject slicing occurs when you assign a derived class object to a base class object.");
    cmsg("The first Animal* will point to an allocated Dog :");
    animalArray[0] = new Dog();
    std::cout << "First Animal in the array = " << animalArray[0]->getType() << std::endl;
    cmsg("We then call the makeSound() method to check that everything's fine :");
    animalArray[0]->makeSound();
    cmsg("The last Animal* will point to an allocated Cat :");
    animalArray[1] = new Cat();
    std::cout << "Second Animal in the array = " << animalArray[1]->getType() << std::endl;
    cmsg("We then call the makeSound() method to check that everything's fine :");
    animalArray[1]->makeSound();
    cmsg("Then we deallocate the heap memory by looping on the Animal* array");
    for (int i = 0 ; i < 2 ; i++)
	    delete animalArray[i];
    testOk(1);
    test("Additionnal Tests, including deep copy checks\n");
    cmsg("A shallow copy is the operation of copying the memory held by each data member of an object to another.\nThis includes for example the memory adress held by a pointer.");
    cmsg("In consequence, if you make a shallow copy of an object that's pointing to allocated memory, the second object's pointer will point to the same location.\nThis can lead to memory leaks etc...");
    cmsg("Calling default constructor on cat_1 && giving him an idea");
    Cat cat_1 = Cat();
    cat_1.add_idea("* I WANT FISH *");
    cmsg("Calling copy constructor on cat_2");
    Cat cat_2(cat_1);
    cmsg("cat_1 && cat_2 shoud share the same idea");
    cmsg("cat_1 :");
    cat_1.show_ideas();
    cmsg("cat_2 :");
    cat_2.show_ideas();
    cmsg("Let's make cat_2 forget about its idea, in case of shallow copy made by the constructor, cat_1 should forget it too :");
    cat_2.remove_idea();
    cmsg("Checking that the idea had been removed :");
    cat_2.show_ideas();
    testOk(1);
    cmsg("Cheking cat_1 ideas :");
    cat_1.show_ideas();
    testOk(1);
    cmsg("Giving cat_2 a new idea and calling assignment overload by assigning cat_2 to cat_3");
    cat_2.add_idea("* I WANT CAT *");
    Cat cat_3 = cat_2;
    cmsg("Adding one more idea to cat_3 so it can think differently from cat_2 (except if the copy is shallow !) :");
    cat_3.add_idea("* I WANT BRAIN *");
    cmsg("cat_3 ideas :");
    cat_3.show_ideas();
    cmsg("cat_2 ideas :");
    cat_2.show_ideas();
    testOk(1);
    cmsg("We are now assigning cat_2 to cat_1 and cat_1 to cat_3, thereby freeing the brains & allocating new ones...");
    cat_1 = cat_2;
    cmsg("showing cat_2 ideas :");
    cat_1.show_ideas();
    cat_3 = cat_1;
    cmsg("showing cat_3 ideas :");
    cat_3.show_ideas();
    cmsg("Instanciating cat_4 with cat_3 should call copy constructor and give cat_4 the same Ideas as cat_3");
    Cat cat_4(cat_3);
    cat_4.add_idea("I WANT HOTDOG");
    cat_4.add_idea("I WANT $$$");
    cmsg("showing cat_4 ideas :");
    cat_4.show_ideas();
    testOk(1);

    test("Now Testing with Dogs to be sure :");
    Dog dog_1 = Dog();
    dog_1.add_idea("* I WANT FISH *");
    cmsg("Calling copy constructor on dog_2");
    Dog dog_2(dog_1);
    cmsg("dog_1 && dog_2 shoud share the same idea");
    cmsg("dog_1 :");
    dog_1.show_ideas();
    cmsg("dog_2 :");
    dog_2.show_ideas();
    cmsg("Let's make dog_2 forget about its idea, in case of shallow copy made by the constructor, dog_1 should forget it too :");
    dog_2.remove_idea();
    cmsg("Checking that the idea had been removed :");
    dog_2.show_ideas();
    testOk(1);
    cmsg("Cheking dog_1 ideas :");
    dog_1.show_ideas();
    testOk(1);
    cmsg("Giving dog_2 a new idea and calling assignment overload by assigning dog_2 to dog_3");
    dog_2.add_idea("* I WANT CAT *");
    Dog dog_3 = dog_2;
    cmsg("Adding one more idea to dog_3 so it can think differently from dog_2 (except if the copy is shallow !) :");
    dog_3.add_idea("* I WANT BRAIN *");
    cmsg("dog_3 ideas :");
    dog_3.show_ideas();
    cmsg("dog_2 ideas :");
    dog_2.show_ideas();
    testOk(1);
    cmsg("We are now assigning dog_2 to dog_1 and dog_1 to dog_3, thereby freeing the brains & allodoging new ones...");
    dog_1 = dog_2;
    cmsg("showing dog_2 ideas :");
    dog_1.show_ideas();
    dog_3 = dog_1;
    cmsg("showing dog_3 ideas :");
    dog_3.show_ideas();
    cmsg("Instanciating dog_4 with dog_3 should call copy constructor and give dog_4 the same Ideas as dog_3");
    Dog dog_4(dog_3);
    dog_4.add_idea("I WANT HOTDOG");
    dog_4.add_idea("I WANT $$$");
    cmsg("showing dog_4 ideas :");
    dog_4.show_ideas();
    testOk(1);
    return (0);
}
