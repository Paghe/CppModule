#include "Bureaucrat.hpp"

void	Bureaucrat::GradeTooHighException(int grade)
{
	if (grade <  1)
		throw std::exception();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)  : _name(name)
{
	try
			GradeTooHighException(grade);
	catch (std::exception& e)
		std::cout << "Too high" << std::endl;
}

Bureaucrat::G

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




