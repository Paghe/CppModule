#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
private:
	std::string const _name;
	bool _signed;
	const int _gradeSigned;
	const int _gradeExec;
public:
	virtual std::string getName() const;
	bool	getSigned() const;
	int 	getGradeSigned() const;
	int 	getGradeExec() const;
	void	beSigned(const Bureaucrat &other);
	virtual void execute(Bureaucrat const & executor) const = 0;
	AForm(std::string const &name, const int gradeSigned, const int gradeExec);
	AForm(const AForm & set);
	AForm& operator=(AForm const & copy);
	virtual ~AForm();
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

std::ostream & operator<<(std::ostream &cout, const AForm &other);

#endif