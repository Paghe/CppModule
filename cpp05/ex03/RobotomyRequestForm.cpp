#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)  :
AForm("RobotmyRequestForm", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &set) :
AForm(set.getName(), set.getTarget(), set.getGradeSigned(), set.getGradeExec())
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm & copy)
{
	AForm::operator=(copy);
	return (*this);
}
void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
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
		std::srand(time(0));
		random = std::rand();
		std::cout << "Making a drilling noises..." << std::endl;
		if (random % 2 == 0)
			std::cout << "Robotomy success" << std::endl;
		else
			std::cout << "Robotomy failed" << std::endl;
	}
}
RobotomyRequestForm::~RobotomyRequestForm() {}