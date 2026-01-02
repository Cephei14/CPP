#include "Span.hpp"
#include <ctime>

int main()
{
	{
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	try
	{
		Span Man(10000);
		std::vector<int> ManNums;
		for(int i = 0; i < 10000; i++)
			ManNums.push_back(std::rand());
		Man.addNumbers(ManNums.begin(), ManNums.end());

		std::cout << "Total size : " << ManNums.size() << std::endl;
		std::cout << "Longest span : " << Man.longestSpan() << std::endl;
		std::cout << "Shortest span : " << Man.shortestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}