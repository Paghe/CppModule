#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
            std::string _type;
public:
    Animal();
    Animal(std::string type);
    Animal(Animal const & set);
    Animal& operator=(Animal const & set);
    virtual ~Animal(void);
    std::string getType(void) const;
    virtual void makeSound(void) const = 0;

};

#endif