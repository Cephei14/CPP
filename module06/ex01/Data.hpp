#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

struct Data
{
private:
	std::string _name;
    int _number;
public:
	Data();
	Data(const Data& other);
	Data& operator=(const Data& other);
	~Data();
	
	Data(std::string, int);

	std::string getName() const;
    int getNumber() const;
};

#endif