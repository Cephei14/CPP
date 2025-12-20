#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern bean;
	AForm* form;

	form = bean.makeForm("robotomy request", "saber");
	if(form)
	{
		std::cout << *form << std::endl;
		delete form;
	}
	std::cout << "---------------------------------" << std::endl;
    form = bean.makeForm("coffee request", "bender");
    if (form)
    {
        std::cout << *form << std::endl;
        delete form;
    }
}
