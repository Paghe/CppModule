#include "Animal.hpp"

Animal::Animal()
{
    this->_type = "Animal default";
    std::cout << "Animal constructor with default type called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal constructor built" << std::endl;
}

Animal::Animal(Animal const & set)
{
    this->_type = set.getType();
}

Animal& Animal::operator=(Animal const & set)
{
    this->_type = set._type;
    return (*this);
}

std::string Animal::getType(void) const
{
    return (this->_type);
}

void Animal::makeSound() const
{
    std::cout << this->_type << " makes sound" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor destroyed" << std::endl;
}
