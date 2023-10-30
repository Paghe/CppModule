#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void leaks(void)
{
    system("leaks Brain");
}

int main(void)
{
//    atexit(leaks);
    const Animal* Doggo = new Dog();
    const Animal* Cato = new Cat();
	Dog Dawg("Dawg");
	Cat Kity("Kity");
	Doggo->makeSound();
	Cato->makeSound();
	Dawg.makeSound();
	Kity.makeSound();
    delete Doggo;
    delete Cato;
    return (0);
}