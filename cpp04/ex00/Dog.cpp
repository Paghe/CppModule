#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->_type = "Dog default";
    std::cout << "Dog constructor with default type called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "Dog constructor built" << std::endl;
    this->_type = type;
}

void Dog::makeSound() const
{
    std::cout << "This " << this->_type << " is barks 🐶" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destroyed" << std::endl;
}