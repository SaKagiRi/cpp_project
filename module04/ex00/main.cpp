#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void) {
  {
    Animal animal;
    Animal *dog = new Dog();
    Animal *cat = new Cat();

    animal.makeSound();
    dog->makeSound();
    cat->makeSound();
	delete dog;
	delete cat;
  }

  std::cout << std::endl;

  {
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();

	delete meta;
	delete i;
	delete j;
  }

  std::cout << std::endl;

  {
	  WrongAnimal*	animal = new WrongAnimal();
	  WrongAnimal*	cat = new WrongCat();

	  std::cout << animal->getType() << " say :"<< std::endl;
	animal->makeSound();

	  std::cout << cat->getType() << " say :"<< std::endl;
	cat->makeSound();

	delete animal;
	delete cat;
  }
}
