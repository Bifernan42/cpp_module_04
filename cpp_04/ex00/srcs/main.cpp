#include "../includes/WrongCat.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

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
	test("Mandatory Part");
	cmsg("Every base class pointer can store the adress of a derived object");
	cmsg("Declaring Animals pointers and assigning 3 differents objects, two of which are from derived classes Dog & Cat");
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	cmsg("Outputing Dog type : ");
	std::cout << j->getType() << " " << std::endl;
	cmsg("Outputing Cat type : ");
	std::cout << i->getType() << " " << std::endl;
	cmsg("By using the virtual keyword in function definition we allow polymorphism");
	cmsg("Outputing Cat sound : ");
	i->makeSound(); //will output the cat sound!
	cmsg("Outputing Dog sound : ");
	j->makeSound();
	cmsg("Outputing Animal sound : ");
	meta->makeSound();
	cmsg("Freeing allocated memory using delete operator : ");
	delete meta;
	delete i;
	delete j;
	testOk(1);
	test("Second Part with WrongAnimals...");
	cmsg("Without the keyword virtual, reference to member functions are processed during compile time and not runtime so we are not getting the overloaded functions like before");
	const WrongAnimal* meta_2 = new WrongAnimal();
	const WrongAnimal* i_2 = new WrongCat();
	std::cout << "WrongAnimal type = " << i_2->getType() << " " << std::endl;
	cmsg("Outputing the WrongCat sound : ");
	i_2->makeSound(); //will output the animal sound!
	cmsg("Without Polymorphism, calling a method from an object pointed to calls the method related to the pointer type");
	cmsg("Outputing WrongAnimal sound : ");
	meta_2->makeSound();
	cmsg("Freeing allocated memory using delete operator : ");
	delete meta_2;
	delete i_2;
	testOk(0);
	return (0);
}
