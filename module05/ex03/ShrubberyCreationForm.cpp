#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
	std::cout << "ShrubberyCreationForm Default constructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm Copy constructor is called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	std::cout << "ShrubberyCreationForm Copy assignment operator is called" << std::endl;
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Default destructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Parameterized constructor is called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if(this->getSigned() == false)
		throw AForm::SignException();
	if(this->get_ToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::string filename = this->_target + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	if(outfile.is_open())
	{
		outfile << "      _____  " << std::endl;
		outfile << "     /*****\\ " << std::endl;
		outfile << "   /*********\\ " << std::endl;
		outfile << "  /***********\\ " << std::endl;
		outfile << " |*************\\ " << std::endl;
		outfile << " |*************| " << std::endl;
		outfile << "  ---******---" << std::endl;
		outfile << "     ****** " << std::endl;
		outfile << "       ||" << std::endl;
		outfile << "       ||" << std::endl;
		outfile << "      //\\\\" << std::endl;
		outfile.close();
	}
	else
		std::cerr << "Error: I couldn't open the file!" << std::endl;
}