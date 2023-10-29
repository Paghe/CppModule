#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
        Cat();
        Cat(std::string type);
		Cat(Cat const & preset);
		Cat& operator=(Cat const &  cpy);
        ~Cat(void);
        void makeSound(void) const;

};

#endif