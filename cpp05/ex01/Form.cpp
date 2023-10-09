#include "Form.hpp"

Form::Form(std::string const &name, const int gradeSigned, const int gradeExec) :
	_name(name),
	_signed(false),
	_gradeSigned(gradeSigned),
	_gradeExec(gradeExec)
{
	if (gradeExec > 150 || gradeSigned > 150)
		throw Form::GradeTooLowException();
	else if (gradeExec < 1 || gradeSigned > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form & set) :
_name(set._name),
_signed(set._signed),
_gradeSigned(set._gradeSigned),
_gradeExec(set._gradeExec)
{}


Form& Form::operator=(Form const & copy)
{
	if (this != &copy)
		this->_signed = copy.getSigned();
	return (*this);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getGradeExec() const
{
	return (this->_gradeExec);
}

int Form::getGradeSigned() const
{
	return (this->_gradeSigned);
}

std::string Form::getName() const
{
	return (this->_name);
}

void	Form::beSigned(const Bureaucrat &other)
{
	if (other.getGrade() <= this->_gradeSigned)
		this->_signed = true;
}

void Form::signForm()
{

}
std::ostream & operator<<(std::ostream &cout, const Form &other)
{
	cout << other.getName();
	if (other.getSigned())
		cout << "can sign";
	else
		cout << "can't sign";
 	cout << "the signed grade is ";
	 cout << other.getGradeSigned();
	 cout << "the exec grade is";
	 cout << other.getGradeExec();
	return (cout);
}
Form::~Form() {}