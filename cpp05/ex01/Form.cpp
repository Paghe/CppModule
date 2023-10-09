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

Form::~Form() {}