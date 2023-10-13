#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &set)
{
	*this = set;
}

Intern& Intern::operator=(const Intern &cpy)
{
	if (this != &cpy)
		return (*this);
	else
		exit(1);
}

static AForm *ShrubberyRequest(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *PresidentialRequest(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *RobotmyRequest(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

typedef AForm *(*Form_Array_Ptr)(const std::string &target);

AForm *Intern::makeForm(std::string name, std::string target)
{
	Form_Array_Ptr Form_Array[FORM_ARRAY] = {&ShrubberyRequest, &PresidentialRequest, &RobotmyRequest};
	std::string match_array[FORM_ARRAY] = {"ShrubberyRequest", "PresidentialRequest", "RobotmyRequest"};
	for (int i = 0; i < FORM_ARRAY; i++)
	{
		if (match_array[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (Form_Array[i](target));
		}

	}
	std::cout << "Intern can't create " << name << std::endl;
	return (nullptr);
}
 Intern::~Intern() {}