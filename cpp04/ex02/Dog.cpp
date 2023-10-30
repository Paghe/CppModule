#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->_BrainDog = new Brain();
    this->_type = "Dog default";
    std::cout << "Dog constructor with default type called" << std::endl;
}

Dog::Dog(const Dog & preset) : Animal()
{
	this->_BrainDog = new Brain(*(preset._BrainDog));
	this->_type = preset.getType();
}

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "Dog constructor built" << std::endl;
    this->_type = type;
}

void	Dog::setIdeaByDog(std::string idea, int idx)
{
	if (idx > 99 || idx < 0)
	{
		std::cout << "Out of bounds" << std::endl;
		return ;
	}
	this->_BrainDog->setIdeas(idea, idx);
}

std::string	Dog::getIdeByDog(int idx)
{
	return (this->_BrainDog->getIdeas(idx));
}

Dog& Dog::operator=(Dog const & set)
{
    if (this != &set)
    {
        delete _BrainDog;
        this->_type = set._type;
        _BrainDog = new Brain(*(set._BrainDog));
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "This " << this->_type << " is barks 🐶" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destroyed" << std::endl;
    delete _BrainDog;
}