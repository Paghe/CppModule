#pragma once

#include "Form.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm & set);
	RobotomyRequestForm& operator=(RobotomyRequestForm const & copy);
	void	execute(const Bureaucrat &executor) const;
	~RobotomyRequestForm();
};
