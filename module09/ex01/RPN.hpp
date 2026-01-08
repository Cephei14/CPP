#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <cctype>

class RPN
{
public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	static void Calculate(const std::string& expression);
	static bool IsValid(const std::string& expression);
	static bool IsToken(char c);
};

#endif