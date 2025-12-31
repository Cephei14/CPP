#ifndef WHATEVER_CPP
#define WHATEVER_CPP

#include <iostream>
#include <string>

template <typename T>
void swap(T& a, T& b)
{
	T c;
	c = a;
	a = b;
	b = c;
}

template <typename MN>
MN min(MN& a, MN& b)
{
	if (a < b)
		return a;
	return b;
}

template <typename MX>
MX max(MX& a, MX& b)
{
	if (a > b)
		return a;
	return b;
}

#endif