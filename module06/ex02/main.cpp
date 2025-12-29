#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base* generate(void)
{
    int i = std::rand() % 3;
	if (i == 0)
	{
		std::cout <<"Generated: A"<< std::endl;
		return new A();
	}
	else if (i == 1)
	{	
		std::cout <<"Generated: B"<< std::endl;
		return new B();
	}
	else
	{
		std::cout <<"Generated: C"<< std::endl;
		return new C();
	}
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch(...)
	{
	}
	try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (...)
	{
	}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (...)
	{
	}
    std::cout << "Unknown" << std::endl;
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    Base* unkown = generate();
    identify(unkown);
    identify(*unkown);
	delete unkown;
    return 0;
}