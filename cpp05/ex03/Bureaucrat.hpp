#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class AForm;
class Bureaucrat
{
	public:
			Bureaucrat(std::string const name, int grade);
			Bureaucrat(const Bureaucrat & set);
			Bureaucrat(int grade);
			Bureaucrat& operator=(Bureaucrat const &copy);
			~Bureaucrat(void);
	std::string	getName(void) const;
	void	signForm(AForm &AForm);
	int		getGrade(void) const;
	void 	setGrade(int grade);
	void	incrementGrade(void);
	void	decrementGrade(void);
	void	executeForm(AForm const & form);

class 	GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade too high!");
			}
	};

	class 	GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade too low!");
			}
	};
private:
		std::string const _name;
		int _grade;



};

std::ostream & operator<<(std::ostream &cout, const Bureaucrat &other);

#endif