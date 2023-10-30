#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void leaks(void)
{
    system("leaks Brain");
}

int main(void)
{
//	atexit(leaks);
    const Animal* j = new Dog();
	Dog Doggo;
	Doggo.setIdeaByDog("Feed me Lord!", 0);
	std::cout << "-------->>" << Doggo.getIdeByDog(0) << std::endl;
	Cat Cato;
	Cato.setIdeaByCat("I'm your Lord!", 0);
	std::cout << "-------->>" << Cato.getIdeaByCat(0) << std::endl;
    const Animal* i = new Cat();
    delete j;
    delete i;
    return (0);
}