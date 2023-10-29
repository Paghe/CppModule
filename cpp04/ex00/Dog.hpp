#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
	Dog(Dog const & preset);
	Dog& operator=(Dog const & cpy);
    Dog(std::string type);
    ~Dog();
    void makeSound(void) const;
};

#endif