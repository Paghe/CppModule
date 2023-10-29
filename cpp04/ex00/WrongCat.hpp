#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
	WrongCat(const WrongCat & preset);
	WrongCat& operator=(WrongCat const &cpy);
    WrongCat(std::string type);
    ~WrongCat(void);
    void makeSound(void) const;

};

#endif