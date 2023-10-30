#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal()
{
    this->_BrainCat = new Brain();
    this->_type = "Cat default";
    std::cout << "Cat constructor with default type called" << std::endl;
}

Cat::Cat(const Cat & preset) : Animal()
{
	this->_BrainCat = new Brain(*(preset._BrainCat));
	this->_type = preset.getType();
}

void	Cat::setIdeaByCat(std::string idea, int idx)
{
	if (idx > 99 || idx < 0)
	{
		std::cout << "Out of bounds" << std::endl;
		return ;
	}
	this->_BrainCat->setIdeas(idea, idx);
}

std::string	Cat::getIdeaByCat(int idx)
{
	return (this->_BrainCat->getIdeas(idx));
}
	Cat& Cat::operator=(Cat const & set)
{
    if (this != &set)
    {
        delete _BrainCat;
        this->_type = set._type;
        _BrainCat = new Brain(*(set._BrainCat));
    }
    return (*this);
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
    delete _BrainCat;
}
