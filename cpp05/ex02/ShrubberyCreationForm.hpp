#pragma once
#include "Form.hpp"
#include <fstream>
class ShrubberyCreationForm : public AForm
{
public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm & set);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const & copy);
		void	execute(const Bureaucrat &executor) const;
		~ShrubberyCreationForm();
private:
};