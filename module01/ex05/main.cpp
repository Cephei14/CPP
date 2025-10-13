#include "Harl.hpp"

int main(void)
{
	Harl problem;

	problem.complain("DEBUG");
	problem.complain("INFO");
	problem.complain("ERROR");
	problem.complain("WARNING");
	problem.complain("NOTHING");
	
	return 0;
}