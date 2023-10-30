	#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor built" << std::endl;
}

Brain::Brain(Brain const & set)
{
    *this = set;
}
void	Brain::setIdeas(std::string idea, int idx)
{
	if (idx > 99 || idx < 0)
	{
		std::cout << "Out of bounds!" << std::endl;
		return ;
	}
	this->_ideas[idx] = idea;
}
std::string Brain::getIdeas(int i)
{
    if (i >= 0 && i <= 99 && !this->_ideas[i].empty())
        return (this->_ideas[i]);
    else
        return (std::string());
}

Brain& Brain::operator=(Brain const & set)
{
    for(int i = 0 ; i < 100 ; i++)
        this->_ideas[i] = set._ideas[i];
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destroyed" << std::endl;
}