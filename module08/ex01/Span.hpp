#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <vector>

class Span
{
private:
	unsigned int _N;
	std::vector<int> _v;
public:
	Span();
	Span(const Span& other);
	Span& operator =(const Span& other);
	~Span();

	Span(unsigned int N);

	void addNumber(int n);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif