#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() : std::stack<T>()
	{
		//std::cout << "MutantStack Default constructor is called" << std::endl;
	}
    
	MutantStack(const MutantStack& other) : std::stack<T>(other)
	{
		//std::cout << "MutantStack copy constructor is called" << std::endl;
	}

    MutantStack& operator=(const MutantStack& other)
	{
		//std::cout << "MutantStack copy assignment operator is called" << std::endl;
        if (this != &other)
            std::stack<T>::operator=(other);
        return *this;
    }

	virtual ~MutantStack()
	{
		//std::cout << "MutantStack destructor is called" << std::endl;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin()
	{
		return this->c.begin();
	}

    iterator end()
	{
		return this->c.end();
	}
	
};

#endif