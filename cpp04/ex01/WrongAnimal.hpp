#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
    std::string _type;
public:
    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(WrongAnimal const & set);
    WrongAnimal& operator=(WrongAnimal const & set);
    virtual ~WrongAnimal(void);
    std::string getType(void) const;
    void makeSound(void) const;
};

#endif