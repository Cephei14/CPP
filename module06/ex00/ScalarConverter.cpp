#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Default constuctor is called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter&)
{
	std::cout << "ScalarConverter copy constuctor is called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
	std::cout << "ScalarConverter copy assignment operator is called" << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Default destuctor is called" << std::endl;
}

void ScalarConverter::convert(std::string literal)
{
	char c = 0;
	int n = 0;
	float f = 0.0f;
	double db = 0.0;

	if(literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
	{
		c = literal[0];
		n = static_cast<int>(c);
		f = static_cast<float>(c);
		db = static_cast<double>(c);
	}
	else
	{
		char* endptr = NULL;
		db = std::strtod(literal.c_str(), &endptr);
		if (*endptr != '\0') 
        {
            if (*endptr == 'f' && *(endptr + 1) == '\0') 
            {
            }
            else 
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: impossible" << std::endl;
                std::cout << "double: impossible" << std::endl;
                return;
            }
        }
		n = static_cast<int>(db); 
		f = static_cast<float>(db); 
		c = static_cast<char>(db); 
	}
	if(isnan(db) || isinf(db) || db < 0 || db > 127)
		std::cout << "char:  Impossible" << std::endl;
	else if(!std::isprint(c))
		std::cout << "char:  Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	if(isnan(db) || isinf(db) || db < INT_MIN || db > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << n << std::endl;
	if(isnan(f) || isinf(f))
		std::cout << "float: " << f << "f" << std::endl;
	else
	{
		if(f == static_cast<int>(f))
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
	}
	if(isnan(db) || isinf(db))
		std::cout << "double: " << db << std::endl;
	else 
	{
    	if (db == static_cast<int>(db)) 
    	    std::cout << "double: " << db << ".0" << std::endl;
    	else 
    	    std::cout << "double: " << db << std::endl;
	}
}
