#include "Data.hpp"

Data::Data() : _name("Default"), _number(0)
{
    std::cout << "Data Default constructor called" << std::endl;
}

Data::Data(const Data& other) : _name(other._name), _number(other._number)
{
    std::cout << "Data Copy constructor called" << std::endl;
}

Data& Data::operator=(const Data& other)
{
    std::cout << "Data Assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_number = other._number;
    }
    return *this;
}

Data::~Data()
{
    std::cout << "Data Destructor called" << std::endl;
}


Data::Data(std::string s, int n) : _name(s), _number(n)
{
    std::cout << "Data Parameterized constructor called" << std::endl;
}

std::string Data::getName() const 
{ 
    return this->_name; 
}

int Data::getNumber() const 
{ 
    return this->_number; 
}