#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"),  _IsSigned(false), _ToSign(150), _ToExecute(150)
{
	std::cout << "Form Default constructor is called" << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _IsSigned(other._IsSigned), _ToSign(other._ToSign), _ToExecute(other._ToExecute)
{
	std::cout << "Form Copy constructor is called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Form Copy assignment operator is called" << std::endl;
	if (this != &other)
		this->_IsSigned = other._IsSigned;
	return *this;
}

Form::~Form()
{
	std::cout << "Form Default destructor is called" << std::endl;
}

Form::Form(const std::string &name, const int ToSign, const int ToExecute) : _name(name), _IsSigned(false), _ToSign(ToSign), _ToExecute(ToExecute)
{
	std::cout << "Form Parameterized constructor is called" << std::endl;
	if(ToSign < 1 || ToExecute < 1)
		throw Form::GradeTooHighException();
	if(ToSign > 150 || ToExecute > 150)
		throw Form::GradeTooLowException();
}

std::string Form::get_name() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return(this->_IsSigned);
}

int Form::get_ToSign() const
{
    return this->_ToSign;
}

int Form::get_ToExecute() const
{
    return this->_ToExecute;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _ToSign)
		this->_IsSigned = true;
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream& operator<<(std::ostream &os, const Form& f)
{
	os << "Form: " << f.get_name() << std::endl
	<< "Min grade to sign: " << f.get_ToSign() <<std::endl
	<< "Min grade to execute: " << f.get_ToExecute() << std::endl
	<< "Signature status: " << (f.getSigned() ? "Yes" : "No") << std::endl;
	return os;
}