#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	// (1) ----OUT OF RANGE FORMS----//
	try
	{
		Form high1("High1", 0, 0);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error1 caught: " << e.what() << std::endl;
	}
	try
	{
		Form high2("High2", 0, 1);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error2 caught: " << e.what() << std::endl;
	}
	try
	{
		Form high3("High3", 1, 0);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error3 caught: " << e.what() << std::endl;
	}

	try
	{
		Form Low1("Low1", 151, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error A caught: " << e.what() << std::endl;
	}
	try
	{
		Form Low2("Low2", 150, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error B caught: " << e.what() << std::endl;
	}
	try
	{
		Form Low3("Low3", 151, 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error C caught: " << e.what() << std::endl;
	}
	
	// (2) ---- Bureaucrat signing Low/High Forms ---- //
	
	try
    {
        Bureaucrat John("John", 40);
        Form High_form("HF", 10, 10);
        Form Low_form("LF", 100, 100);

        //Failure
        std::cout << "\n--- TEST A: John (40) vs HF (10) ---" << std::endl;
        std::cout << High_form; //BEFORE
        John.signForm(High_form);
        std::cout << High_form; //AFTER

        //Success
        std::cout << "\n--- TEST B: John (40) vs LF (100) ---" << std::endl;
        std::cout << Low_form;  //BEFORE
        John.signForm(Low_form);
        std::cout << Low_form;  //AFTER
    }
    catch(const std::exception& e)
    {
        std::cerr << "Unexpected Error: " << e.what() << std::endl;
    }
	return 0;
}