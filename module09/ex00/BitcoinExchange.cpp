#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	//std::cout<<"BitcoinExchange Default constructor is called"<<std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	std::cout<<"BitcoinExchange copy constructor is called"<<std::endl;
	this->_CoinsData = other._CoinsData;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	std::cout<<"BitcoinExchange copy assignment is called"<<std::endl;
	if(this != &other)
		this->_CoinsData = other._CoinsData;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	//std::cout<<"BitcoinExchange Destructor is called"<<std::endl;
}

void BitcoinExchange::LoadData(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	std::string line;

	if(!file.is_open())
	{
		std::cerr << "Error : couldn't open csv file." << std::endl;
		return;
	}
	std::getline(file, line);
	while(std::getline(file, line))
	{
		size_t pos = line.find(',');
		if (pos == std::string::npos)
        	continue;
		this->_CoinsData[line.substr(0, pos)] = std::atof(line.substr(pos + 1).c_str());
	}
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    if(date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
				return false;
        }
        else
        {
            if (!isdigit(date[i]))
				return false;
        }
    }
    int Y = std::atoi(date.substr(0, 4).c_str());
    int M = std::atoi(date.substr(5, 2).c_str());
    int D = std::atoi(date.substr(8, 2).c_str());
    if (Y < 0 || M < 1 || M > 12 || D < 1 || D > 31)
        return false;
    if((M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) && D > 31)
        return false;
    else if ((M == 4 || M == 6 || M == 9 || M == 11) && D > 30)
        return false;
    else if (M == 2)
    {
        bool isLeap = (Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0);
        if (isLeap && D > 29)
            return false;
        else if (!isLeap && D > 28)
            return false;
    }
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& value)
{
    char* end;
	double dValue = std::strtod(value.c_str(), &end);

    if (*end != '\0' || end == value.c_str())
    {
        std::cout << "Error: bad input => " << value << std::endl;
        return false;
    }
    if (dValue < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	else if (dValue > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
    return true;
}

void BitcoinExchange::Calculate(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if(!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	if (this->_CoinsData.empty())
    {
        std::cout << "Error: csv file is empty." << std::endl;
        return;
    }
	std::string line;
	while(std::getline(file, line))
	{
		if (line == "date | value")
            continue;
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
            continue;
		}
		std::string Date = line.substr(0, pos) ;
		while (Date.length() > 0 && Date[Date.length() - 1] == ' ')
            Date.resize(Date.length() - 1);
		pos++;
		while (pos < line.length() && line[pos] == ' ')
            pos++;
		std::string Value = line.substr(pos);
		if (!isValidDate(Date))
		{
			std::cout << "Error: bad input ==> " << Date << std::endl;
			continue;
		}
		else if (!isValidValue(Value))
			continue;
        double val = std::strtod(Value.c_str(), NULL);
        std::map<std::string, float>::iterator it = this->_CoinsData.lower_bound(Date);
        if (it == this->_CoinsData.begin() && it->first != Date)
            std::cout << "Error: date too old => " << Date << std::endl;
        else
        {
            if (it == _CoinsData.end() || it->first != Date)
                it--;
            std::cout << Date << " => " << Value << " = " << (val * it->second) << std::endl;
        }
	}
}
