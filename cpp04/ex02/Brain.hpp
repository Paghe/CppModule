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
		void		setIdeas(std::string idea, int idx);
        std::string	getIdeas(int i);
        ~Brain();
};

#endif