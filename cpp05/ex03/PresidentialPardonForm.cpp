#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)  :
		AForm("RobotmyRequestForm", target, 72, 45)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &set) :
		AForm(set.getName(), set.getTarget(), set.getGradeSigned(), set.getGradeExec())
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm & copy)
{
	AForm::operator=(copy);
	return (*this);
}
void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	int	random;

	random = 0;
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	else if (executor.getGrade() < this->getGradeExec())
		throw GradeTooHighException();
	else if (!this->getSigned())
		std::cout << this->getName() << "does not have permission" << std::endl;
	else
	{
		std::cout << this->getTarget() << "has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}
PresidentialPardonForm::~PresidentialPardonForm() {}