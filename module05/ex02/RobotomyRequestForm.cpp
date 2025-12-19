#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	std::cout << "RobotomyRequestForm Default constructor is called " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{
	std::cout << "RobotomyRequestForm Copy constructor is called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	std::cout << "RobotomyRequestForm Copy assignment operator is called" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Default destructor is called" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Parameterized constructor is called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if(this->getSigned() == false)
		throw AForm::SignException();
	if(executor.getGrade() > this->get_ToExecute())
		throw AForm::GradeTooLowException();
	std::cout << "ZZWZWWZWz.... KLANK!" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed for " << this->_target << "." << std::endl;
}