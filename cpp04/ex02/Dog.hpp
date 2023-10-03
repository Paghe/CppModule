#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(std::string type);
    Dog& operator=(Dog const & set);
    ~Dog();
    void makeSound(void) const;
private:
        Brain* _BrainDog;
};

#endif