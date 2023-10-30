#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(std::string type);
	Dog(const Dog & preset);
    Dog& operator=(Dog const & set);
	void		setIdeaByDog(std::string idea, int idx);
	std::string getIdeByDog(int idx);
    ~Dog();
    void makeSound(void) const;
private:
        Brain* _BrainDog;
};

#endif