#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"),  _IsSigned(false), _ToSign(150), _ToExecute(150)
{
	std::cout << "Form Default constructor is called" << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _IsSigned(other._IsSigned), _ToSign(other._ToSign), _ToExecute(other._ToExecute)
{
	std::cout << "Form Copy constructor is called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "Form Copy assignment operator is called" << std::endl;
	if (this != &other)
		this->_IsSigned = other._IsSigned;
	return *this;
}

AForm::~AForm()
{
	std::cout << "Form Default destructor is called" << std::endl;
}

AForm::AForm(const std::string &name, const int ToSign, const int ToExecute) : _name(name), _IsSigned(false), _ToSign(ToSign), _ToExecute(ToExecute)
{
	std::cout << "Form Parameterized constructor is called" << std::endl;
	if(ToSign < 1 || ToExecute < 1)
		throw AForm::GradeTooHighException();
	if(ToSign > 150 || ToExecute > 150)
		throw AForm::GradeTooLowException();
}

std::string AForm::get_name() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return(this->_IsSigned);
}

int AForm::get_ToSign() const
{
    return this->_ToSign;
}

int AForm::get_ToExecute() const
{
    return this->_ToExecute;
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _ToSign)
		this->_IsSigned = true;
	else
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char* AForm::SignException::what() const throw()
{
	return ("Form is not signed!");
}

std::ostream& operator<<(std::ostream &os, const AForm& f)
{
	os << "Form: " << f.get_name() << std::endl
	<< "Min grade to sign: " << f.get_ToSign() <<std::endl
	<< "Min grade to execute: " << f.get_ToExecute() << std::endl
	<< "Signature status: " << (f.getSigned() ? "Yes" : "No") << std::endl;
	return os;
}