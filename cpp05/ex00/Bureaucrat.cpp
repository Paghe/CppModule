#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}
Bureaucrat::Bureaucrat(int grade) : _name("default")
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

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

void	Bureaucrat::incrementGrade(void)
{
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::decrementGrade(void)
{
	this->_grade++;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream & operator<<(std::ostream &cout, const Bureaucrat &other)
{
	cout << other.getName();
	cout << " ";
	cout << other.getGrade();
	return (cout);
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &copy)
{
	this->_grade = copy.getGrade();
	return (*this);
}


