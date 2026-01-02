#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	for(int i = -5; i <= 10; i++)
		v.push_back(i);
	try
	{
		std::cout << "Searching for 5..." << std::endl;
		std::vector<int>::iterator result = easyfind(v , 5);
		std::cout << "Found: " << *result << std::endl;
	}
	catch (const char* str)
	{
		std::cout << str << std::endl;
	}
	try
	{
        std::cout << "Searching for 100..." << std::endl;
		std::vector<int>::iterator result = easyfind(v, 100);
		std::cout << "Found: " << *result << std::endl;
    }
    catch (const char* str)
    {
        std::cerr << str << std::endl;
    }
	return 0;
}