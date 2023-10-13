#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
		AForm("ShrubberyCreationForm", target, 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & set) :
		AForm(set.getName(), set.getTarget(),set.getGradeSigned(), set.getGradeExec())
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	AForm::operator=(copy);
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	else if (executor.getGrade() < this->getGradeExec())
		throw GradeTooHighException();
	else if (this->getSigned() == false)
		std::cout << this->getName() << "does not have permission" << std::endl;
	else
	{
		std::ofstream out(getTarget() + "_shrubbery");
		out << "/n"
			   "   .        +          .      .          .\n"
			   "     .            _        .                    .\n"
			   "  ,              /;-._,-.____        ,-----.__\n"
			   " ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n"
			   "  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n"
			   "                      ,    `./  \\:. `.   )==-'  .\n"
			   "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n"
			   ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n"
			   "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n"
			   "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n"
			   "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n"
			   "              \\:  `  X` _| _,\\/'   .-'\n"
			   ".               \":._:`\\____  /:'  /      .           .\n"
			   "                    \\::.  :\\/:'  /              +\n"
			   "   .                 `.:.  /:'  }      .\n"
			   "           .           ):_(:;   \\           .\n"
			   "                      /:. _/ ,  |\n"
			   "                   . (|::.     ,`                  .\n"
			   "     .                |::.    {\\\n"
			   "                      |::.\\  \\ `.\n"
			   "                      |:::(\\    |\n"
			   "              O       |:::/{ }  |                  (o\n"
			   "               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n"
			   "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n";
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
