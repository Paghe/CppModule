#include "Form.hpp"

AForm::AForm(std::string const &name, const std::string &target, const int gradeSigned, const int gradeExec) :
	_name(name),
	_target(target),
	_signed(false),
	_gradeSigned(gradeSigned),
	_gradeExec(gradeExec)
{
	if (gradeExec > 150 || gradeSigned > 150)
		throw AForm::GradeTooLowException();
	else if (gradeExec < 1 || gradeSigned > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm & set) :
_name(set._name),
_target(set._target),
_signed(set._signed),
_gradeSigned(set._gradeSigned),
_gradeExec(set._gradeExec)
{}


AForm& AForm::operator=(AForm const & copy)
{
	if (this != &copy)
		this->_signed = copy.getSigned();
	return (*this);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getGradeExec() const
{
	return (this->_gradeExec);
}

int AForm::getGradeSigned() const
{
	return (this->_gradeSigned);
}

std::string AForm::getName() const
{
	return (this->_name);
}

std::string AForm::getTarget() const
{
	return (this->_target);
}

void	AForm::beSigned(const Bureaucrat &other)
{
	if (other.getGrade() <= this->_gradeSigned)
		this->_signed = true;
}

std::ostream & operator<<(std::ostream &cout, const AForm &other)
{
	cout << other.getName();
	if (other.getSigned())
		cout << " has been signed";
	else
	{
		cout << " can't be signed";
		cout << " signed grade is ";
		cout << other.getGradeSigned();
		cout << " instead exec grade is ";
		cout << other.getGradeExec();
	}
	 return (cout);
}
AForm::~AForm() {}