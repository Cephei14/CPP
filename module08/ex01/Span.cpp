#include "Span.hpp"

Span::Span() : _N(0), _v()
{
	std::cout << "Span Default constructor is called" << std::endl;
}

Span::Span(const Span& other) : _N(other._N), _v(other._v)
{
	std::cout << "Span copy constructor is called" << std::endl;
}

Span& Span::operator =(const Span& other)
{
	std::cout << "Span copy assignment operator is called" << std::endl;
	if(this != &other)
	{
		this->_N = other._N;
		this->_v = other._v;
	}
	return *this;
}

Span::~Span()
{
	std::cout << "Span destructor is called" << std::endl;
}

Span::Span(unsigned int N) : _N(N)
{
	std::cout << "Span parameterized constructor is called" << std::endl;
	_v.reserve(N);
}

void Span::addNumber(int n)
{
	if(_v.size() >= this->_N)
		throw std::runtime_error("Error : it's full");
	_v.push_back(n);
}

unsigned int Span::shortestSpan()
{
	if (_v.size() < 2)
        throw std::runtime_error("Not enough elements");
    std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
    unsigned int min_span = static_cast<unsigned int> (tmp[1] - tmp[0]);
    for (size_t i = 1; i < tmp.size(); i++)
    {
        if (static_cast<unsigned int> (tmp[i] - tmp[i - 1]) < min_span)
            min_span = tmp[i] - tmp[i - 1];
    }
    return min_span;
}

unsigned int Span::longestSpan()
{
	if(_v.size() < 2)
		throw std::runtime_error("Error : Few elements");
	int MAX = *std::max_element(_v.begin(), _v.end());
	int MIN = *std::min_element(_v.begin(), _v.end());
	return (static_cast<unsigned int>(MAX - MIN));
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (static_cast<unsigned int> (std::distance(begin, end)) > this->_N - this->_v.size())
        throw std::runtime_error("Not enough space");
    _v.insert(_v.end(), begin, end);
}
