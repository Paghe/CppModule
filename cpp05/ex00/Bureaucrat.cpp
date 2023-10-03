#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade)  : _name(name), _grade(grade) {}
Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

Bureaucrat::Bureaucrat(const Bureaucrat &set) : _name(set._name), _grade(set._grade) {}

int Bureaucrat::getGrade() const
{
	return(this->_grade);
}

void Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
}

void	Bureaucrat::GradeTooHighException()
{
	if (this->_grade < 1);
	std::cout <<
}



