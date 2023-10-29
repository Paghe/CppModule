#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->_type = "WrongAnimal default";
    std::cout << "WrongAnimal constructor with default type called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "WrongAnimal constructor built" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & set)
{
    this->_type = set.getType();
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const & set)
{
    this->_type = set.getType();
    return (*this);
}

std::string WrongAnimal::getType(void) const
{
    return (this->_type);
}

void WrongAnimal::makeSound() const
{
    std::cout << this->_type << " makes sound 🚨" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor destroyed" << std::endl;
}
