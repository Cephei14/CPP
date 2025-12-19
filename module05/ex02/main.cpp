#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
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
		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("alpha");
		std::cout << gardener << std::endl;
		std::cout << shrub << std::endl;
		std::cout << saber << std::endl;
		std::cout << robot << std::endl;
		std::cout << "\n[Attempting to execute unsigned form...]" << std::endl;
		gardener.executeForm(shrub);
		saber.executeForm(robot);
		std::cout << "\n[Signing the form...]" << std::endl;
		gardener.signForm(shrub);
		saber.signForm(robot);
		std::cout << "\n[Executing the form...]" << std::endl;
		gardener.executeForm(shrub);
		saber.executeForm(robot);
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
		ShrubberyCreationForm shrub("garden");
		RobotomyRequestForm robot("alpha");
		std::cout << intern << std::endl;
		std::cout << shrub << std::endl;
		std::cout << saber << std::endl;
		std::cout << robot << std::endl;
		std::cout << "\n[Attempting to execute unsigned form...]" << std::endl;
		intern.executeForm(shrub);
		saber.executeForm(robot);
		std::cout << "\n[Signing the form...]" << std::endl;
		intern.signForm(shrub);
		saber.signForm(robot);
		std::cout << "\n[Executing the form...]" << std::endl;
		intern.executeForm(shrub);
		saber.executeForm(robot);
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
		ShrubberyCreationForm shrub("garden");
		RobotomyRequestForm robot("alpha");
		std::cout << intern << std::endl;
		std::cout << shrub << std::endl;
		std::cout << saber << std::endl;
		std::cout << robot << std::endl;
		std::cout << "\n[Signing the form...]" << std::endl;
		intern.signForm(shrub);
		saber.signForm(robot);
		std::cout << "\n[Executing the form...]" << std::endl;
		intern.executeForm(shrub);
		saber.executeForm(robot);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception:" << e.what() << std::endl;
	}
}