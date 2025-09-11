#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define NB_ANIMALS 4

inline void	printNl(int nb)
{
	for (int i = 0; i < nb; i++)
		std::cout << std::endl;
}

inline void	printMess(const std::string message)
{
	std::cout << "/// " << message << " ///" << std::endl;
}

void	arrayTest(void)
{
	Animal *tab[NB_ANIMALS + 1];
	tab[NB_ANIMALS] = NULL;

	printMess("Creating cats");
	for (int i = 0; i < (NB_ANIMALS / 2); i++)
		tab[i] = new Cat();
	printNl(1);

	printMess("Creating dogs");
	for (int i = NB_ANIMALS / 2; i < NB_ANIMALS; i++)
		tab[i] = new Dog();
	printNl(1);

	printMess("All of them making sounds");
	for (int i = 0; i < NB_ANIMALS; i++)
		tab[i]->makeSound();
	printNl(1);

	printMess("Deleting all of them");
	for (int i = 0; i < NB_ANIMALS; i++)
		delete tab[i];
}

inline void	testCopyDog(void)
{
	printMess("Creating Dog 1");
	Dog *d1 = new Dog();
	printNl(1);

	printMess("Setting idea LETS EAT and LETS PLAY");
	d1->getBrain()->setBrain(0,"LETS EAT");
	d1->getBrain()->setBrain(1,"LETS PLAY");

	printMess("Print idea of Dog 1");
	std::cout << "[1] " << d1->getBrain()->getBrain(0) << std::endl;
	std::cout << "[2] " << d1->getBrain()->getBrain(1) << std::endl;
	printNl(1);

	printMess("Creating a copy of Dog 1 in a Dog 2");
	Dog *d2 = new Dog(*d1);
	printNl(1);

	printMess("Kill Dog 1");
	delete d1;
	printNl(1);

	printMess("Print idea of Dog 2");
	std::cout << "[1] " << d2->getBrain()->getBrain(0) << std::endl;
	std::cout << "[2] " << d2->getBrain()->getBrain(1) << std::endl;
	printNl(1);

	printMess("Kill Dog 2");
	delete d2;
	printNl(1);
}

inline void	testCopyCat(void)
{
	printMess("Creating Cat 1");
	Cat *d1 = new Cat();
	printNl(1);

	printMess("Setting idea LETS EAT and LETS PLAY");
	d1->getBrain()->setBrain(0, "LETS EAT");
	d1->getBrain()->setBrain(1, "LETS PLAY");

	printMess("Print idea of Cat 1");
	std::cout << "[1] " << d1->getBrain()->getBrain(0) << std::endl;
	std::cout << "[2] " << d1->getBrain()->getBrain(1) << std::endl;
	printNl(1);

	printMess("Creating a copy of Cat 1 in a Cat 2");
	Cat *d2 = new Cat(*d1);
	printNl(1);

	printMess("Kill Cat 1");
	delete d1;
	printNl(1);

	printMess("Print idea of Cat 2");
	std::cout << "[1] " << d2->getBrain()->getBrain(0) << std::endl;
	std::cout << "[2] " << d2->getBrain()->getBrain(1) << std::endl;
	printNl(1);

	printMess("Kill Cat 2");
	delete d2;
}

int	main(void)
{
	std::cout << "##########################################" << std::endl;
	std::cout << "############### ARRAY TEST ###############" << std::endl;
	std::cout << "##########################################" << std::endl;
	arrayTest();
	printNl(2);

	std::cout << "##########################################" << std::endl;
	std::cout << "############## COPY TEST DOG #############" << std::endl;
	std::cout << "##########################################" << std::endl;
	testCopyDog();
	printNl(2);

	std::cout << "##########################################" << std::endl;
	std::cout << "############## COPY TEST CAT #############" << std::endl;
	std::cout << "##########################################" << std::endl;
	testCopyCat();
	printNl(2);

	// Animal animal;
	//
	// animal.makeSound();
	//
	return (0);
}

// int main(void) {
//   {
//     Animal animal;
//     Animal *dog = new Dog();
//     Animal *cat = new Cat();
//
//     animal.makeSound();
//     dog->makeSound();
//     cat->makeSound();
// 	delete dog;
// 	delete cat;
//   }
//
//   std::cout << std::endl;
//
//   {
//     const Animal *meta = new Animal();
//     const Animal *j = new Dog();
//     const Animal *i = new Cat();
//
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound(); // will output the cat sound!
//     j->makeSound();
//     meta->makeSound();
//
// 	delete meta;
// 	delete i;
// 	delete j;
//   }
//
//   std::cout << std::endl;
// }
