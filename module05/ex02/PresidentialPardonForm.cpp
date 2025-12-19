#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
	std::cout << "PresidentialPardonForm Default constructor is called " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target)
{
	std::cout << "PresidentialPardonForm Copy constructor is called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	std::cout << "PresidentialPardonForm Copy assignment operator is called" << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Default destructor is called" << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm Parameterized constructor is called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if(this->getSigned() == false)
		throw AForm::SignException();
	if(executor.getGrade() > this->get_ToExecute())
		throw AForm::GradeTooLowException();
	std::cout << this->_target << "  has been pardoned by Zaphod Beeblebrox." << std::endl;
}