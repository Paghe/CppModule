#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void leaks(void)
{
	system("leaks Animal");
}

int main(void)
{
//	atexit(leaks);
	const WrongAnimal* WierdAnimal = new WrongAnimal();
	const Animal* RightDog = new Dog("Gennaro");
	const Cat*	RighCat = new Cat("PSPS");
	const WrongAnimal* FalseCat = new WrongCat();
	std::cout << RightDog->getType() << " <------" << std::endl;
	std::cout << FalseCat->getType() << " <------" << std::endl;
	std::cout << RighCat->getType() << " <------" << std::endl;
	std::cout << WierdAnimal->getType() << " <------" << std::endl;
	std::cout << "CAT SOUND ---> ";
	RighCat->makeSound(); //will output the cat sound
 	FalseCat->makeSound();
 	std::cout << "DOG SOUND ---> ";
 	RightDog->makeSound(); //will output the dog sound
 	WierdAnimal->makeSound();
 	delete WierdAnimal;
 	delete RightDog;
 	delete FalseCat;
 	delete RighCat;
 	return (0);
}