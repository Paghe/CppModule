#pragma once

#include "Form.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm & set);
	PresidentialPardonForm& operator=(PresidentialPardonForm const & copy);
	void	execute(const Bureaucrat &executor) const;
	~PresidentialPardonForm();
};
