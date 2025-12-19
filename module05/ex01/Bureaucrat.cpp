#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout<<"Bureaucrat Default constructor is called"<<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout<<"Bureaucrat copy constructor is called"<<std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout<<"Bureaucrat copy assignment is called"<<std::endl;
	if(this != &other)
		this->_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Bureaucrat Destructor is called"<<std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	std::cout<<"Bureaucrat Parameterized constructor is called"<<std::endl;
	if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::increment()
{
	if(this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrement()
{
	if(this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

void Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.get_name() << std::endl;
    }
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign " << f.get_name() << " because " << e.what() << std::endl;
	}
}
