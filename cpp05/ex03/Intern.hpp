#pragma once

#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#define FORM_ARRAY 3

class Intern
{
public:
	Intern();
	Intern(const Intern & set);
	Intern& operator=(Intern const & cpy);
	~Intern();
	AForm *makeForm(std::string name, std::string target);

};