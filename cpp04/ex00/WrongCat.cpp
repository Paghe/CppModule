#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->_type = "WrongCat default";
    std::cout << "WrongCat constructor with default type called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
    std::cout << "WrongCat constructor built" << std::endl;
    this->_type = type;
}

WrongCat::WrongCat(const WrongCat &preset)  : WrongAnimal(preset)
{
	this->_type = preset.getType();
}

WrongCat& WrongCat::operator=(const WrongCat &cpy)
{
	WrongAnimal::operator=(cpy);
	return (*this);
}

void    WrongCat::makeSound() const
{
    std::cout << "this " << this->_type << " meows! 🐈" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destroyed" << std::endl;
}
