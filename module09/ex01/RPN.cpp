#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
	(void)other;
}

RPN& RPN::operator=(const RPN& other)
{
	(void)other;
	return *this;
}

RPN::~RPN()
{
}


bool RPN::IsToken(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

bool RPN::IsValid(const std::string& expression)
{
	int TokenNb = 0;
	int IntNb = 0;
	if(expression.empty() || (expression[0] > '9' || expression[0] < '0'))
	{
		std::cerr << "Error : RPN should start with a number !" << std::endl;
		return false;
	}
	for(size_t i = 0; i < expression.length(); i++)
	{
		if(expression[i] <= '9' && expression[i] >= '0')
		{
			IntNb++;
			if (expression[i + 1] && expression[i + 1] != ' ')
			{
				std::cerr << "Error : Numbers should be separated by a space !" << std::endl;
				return false;
			}
		}
		else if(IsToken(expression[i]))
		{
			TokenNb++;
			if (expression[i + 1] && expression[i + 1] != ' ')
			{
				std::cerr << "Error : Tokens should be separated by a space !" << std::endl;
				return false;
			}
		}
		else if (expression[i] == ' ')
			continue;
		else
		{
			std::cerr << "Error : invalid token" << std::endl;
			return false;
		}
	}
	if (IntNb == TokenNb + 1)
		return true;
	std::cerr << "Error : Invalid inverted Polish mathematical expression" << std::endl;
	return false;
}

void RPN::Calculate(const std::string& expression)
{
	if (!IsValid(expression))
		return;
	std::stack<double> data;
	double tmp;
	for (size_t i = 0; i < expression.length(); i++)
	{
		if(isdigit(expression[i]))
			data.push(expression[i] - '0');
		else if(IsToken(expression[i]))
		{
			if (data.size() < 2)
    		{
    		    std::cerr << "Error: not enough operands." << std::endl;
    		    return;
    		}
			tmp = data.top();
			data.pop();
			if (expression[i] == '+')
				tmp = data.top() + tmp;
			else if (expression[i] == '-')
				tmp = data.top() - tmp;
			else if (expression[i] == '*')
				tmp = data.top() * tmp;
			else if (expression[i] == '/')
			{
				if (tmp == 0)
				{
					std::cerr << "Error : Cannot divide by 0 !" << std::endl;
					return;
				}
				tmp = data.top() / tmp;
			}
			data.pop();
			data.push(tmp);
		}
	}
	std::cout << data.top() << std::endl;
}