#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
	public:
			Bureaucrat(const std::string name, int grade);
			Bureaucrat(const Bureaucrat & set);
			~Bureaucrat(void);
			std::string	getName(void) const;
	int		getGrade(void) const;
	void 	setGrade(int grade);
	void	GradeTooHighException(void);
	void	Bureaucrat::GradeTooLowException(void);
private:
		const std::string _name;
		int _grade;



};
#endif