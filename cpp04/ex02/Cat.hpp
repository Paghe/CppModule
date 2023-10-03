#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal
{
public:
        Cat();
        Cat(std::string type);
        Cat& operator=(Cat const & set);
        ~Cat();
        void makeSound(void) const;
private:
    Brain* _BrainCat;
};

#endif