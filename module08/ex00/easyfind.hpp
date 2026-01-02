#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <vector>

template <typename T>
typename T::iterator easyfind(T& n, int i)
{
	typename T::iterator it = std::find(n.begin(), n.end(), i);
	if(it == n.end())
		throw "Value not found";
	return it;
}

#endif