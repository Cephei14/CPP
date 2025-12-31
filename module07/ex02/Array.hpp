#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <ctime>
#include <exception>

template <typename T>
class Array
{
private:
	T* _arr;
	unsigned int _len;
public:
	Array()
	{
		std::cout << "Array default constructor is called" << std::endl;
		this->_arr= NULL;
		this->_len = 0;	
	};

	Array(unsigned int n)
	{
		std::cout << "Array parameterized constructor is called" << std::endl;
		this->_arr= new T[n]();
		this->_len = n;
	};

	Array(const Array& other)
	{
		std::cout << "Array copy constructor is called" << std::endl;
		this->_arr = new T[other._len];
		for (unsigned int i = 0; i < other._len; i++)
			this->_arr[i] = other._arr[i];
		this->_len = other._len;
	};

	Array& operator=(const Array& other)
	{
		std::cout << "Array copy operator assignment is called" << std::endl;
		if(this != &other)
		{
			if(this->_arr)
				delete[] this->_arr;
			this->_len = other._len;
			this->_arr = new T[other._len];
			for (unsigned int i = 0; i < this->_len; i++)
				this->_arr[i] = other._arr[i];
		}
		return *this;
	};

	~Array()
	{
		std::cout << "Array destructor is called" << std::endl;
		if(this->_arr)
			delete[] (this->_arr);
	};
	unsigned int size() const
    {
        return this->_len;
    }

    T& operator[](unsigned int index)
    {
        if (index >= this->_len)
            throw std::exception();
        return this->_arr[index];
    }
};

#endif