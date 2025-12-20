#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default constructor is called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "Intern Copy constructor is called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	std::cout << "Intern Copy assignment operator is called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern Default destructor is called" << std::endl;
}

static AForm* makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm* makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm* makePresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string FormName, std::string target)
{
	struct FormPair
	{
		std::string name;
		AForm* (*func)(std::string);
	};
	FormPair forms[] = {
		{ "shrubbery creation", &makeShrubbery },
        { "robotomy request", &makeRobotomy },
        { "presidential pardon", &makePresidential }
    };
	for(int i = 0; i <= 2; i++)
	{
		if(forms[i].name == FormName)
		{
			std::cout << "Intern creates " << FormName << std::endl;
			return (forms[i].func(target));
		}
	}
	std::cout << "Intern cannot create " << FormName << " because it does not exist" << std::endl;
	return NULL;
}