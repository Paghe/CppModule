#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->_type = "Cat default";
    std::cout << "Cat constructor with default type called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
    std::cout << "Cat constructor built" << std::endl;
    this->_type = type;
}

void    Cat::makeSound() const
{
    std::cout << "this " << this->_type << " meows! 🐈" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destroyed" << std::endl;
}
