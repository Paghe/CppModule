#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
private:
	std::string const _name;
	bool _signed;
	const int _gradeSigned;
	const int _gradeExec;
public:
	std::string getName() const;
	bool	getSigned() const;
	int 	getGradeSigned() const;
	int 	getGradeExec() const;
	void	beSigned(const Bureaucrat &other);
	Form(std::string const &name, const int gradeSigned, const int gradeExec);
	Form(const Form & set);
	Form& operator=(Form const & copy);
	~Form();
class GradeTooHighException : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return("Grade Too High");
	}
};
class GradeTooLowException : public std::exception{
public:
	virtual const char* what() const throw()
	{
		return("Grade Too Low");
	}
};

};

std::ostream & operator<<(std::ostream &cout, const Form &other);

#endif