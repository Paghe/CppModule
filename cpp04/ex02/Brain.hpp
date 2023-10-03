#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private :
        std::string _ideas[100];
public:
        Brain();
        Brain(Brain const & set);
        Brain& operator=(Brain const & set);
        std::string getIdeas(int i);
        ~Brain();
};

#endif