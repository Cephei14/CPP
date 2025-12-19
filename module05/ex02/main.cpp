#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	try
	{
		std::srand(std::time(NULL));
		std::cout << "==== TEST1: BUREAUCRAT CAN SIGN CAN EXCECUTE CASE ====" << std::endl;
		Bureaucrat gardener("Gardener", 137);
		Bureaucrat saber("Saber", 44);
		Bureaucrat president("President", 1);
		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("alpha");
		PresidentialPardonForm high("order");
		std::cout << gardener << std::endl;
		std::cout << shrub << std::endl;
		std::cout << saber << std::endl;
		std::cout << robot << std::endl;
		std::cout << president << std::endl;
		std::cout << high << std::endl;
		std::cout << "\n[Attempting to execute unsigned form...]" << std::endl;
		gardener.executeForm(shrub);
		saber.executeForm(robot);
		president.executeForm(high);
		std::cout << "\n[Signing the form...]" << std::endl;
		gardener.signForm(shrub);
		saber.signForm(robot);
		president.signForm(high);
		std::cout << "\n[Executing the form...]" << std::endl;
		gardener.executeForm(shrub);
		saber.executeForm(robot);
		president.executeForm(high);
		std::cout << "\nSUCCESS! Check your directory for 'home_shrubbery'." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception:" << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "==== TEST2: BUREAUCRAT CAN SIGN CANNOT EXCECUTE CASE ====" << std::endl;
		Bureaucrat intern("Intern", 140);
		Bureaucrat saber("Saber", 50);
		Bureaucrat PM("Manager", 10);
		ShrubberyCreationForm shrub("garden");
		RobotomyRequestForm robot("alpha");
		PresidentialPardonForm high("order");
		std::cout << intern << std::endl;
		std::cout << shrub << std::endl;
		std::cout << saber << std::endl;
		std::cout << robot << std::endl;
		std::cout << PM << std::endl;
		std::cout << high << std::endl;
		std::cout << "\n[Attempting to execute unsigned form...]" << std::endl;
		intern.executeForm(shrub);
		saber.executeForm(robot);
		PM.executeForm(high);
		std::cout << "\n[Signing the form...]" << std::endl;
		intern.signForm(shrub);
		saber.signForm(robot);
		PM.signForm(high);
		std::cout << "\n[Executing the form...]" << std::endl;
		intern.executeForm(shrub);
		saber.executeForm(robot);
		PM.executeForm(high);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception:" << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "==== TEST3: BUREAUCRAT CANNOT SIGN CANNOT EXCECUTE CASE ====" << std::endl;
		Bureaucrat intern("Intern", 149);
		Bureaucrat saber("Saber", 149);
		Bureaucrat secretary("Joe", 149);
		ShrubberyCreationForm shrub("garden");
		RobotomyRequestForm robot("alpha");
		PresidentialPardonForm high("order");
		std::cout << intern << std::endl;
		std::cout << shrub << std::endl;
		std::cout << saber << std::endl;
		std::cout << robot << std::endl;
		std::cout << secretary << std::endl;
		std::cout << high << std::endl;
		std::cout << "\n[Signing the form...]" << std::endl;
		intern.signForm(shrub);
		saber.signForm(robot);
		secretary.signForm(high);
		std::cout << "\n[Executing the form...]" << std::endl;
		intern.executeForm(shrub);
		saber.executeForm(robot);
		secretary.executeForm(high);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception:" << e.what() << std::endl;
	}
}