#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{

private:
	std::string const _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat(const std::string& name, int grade);
	std::string getName() const;
	int getGrade() const;
	void increment();
	void decrement();

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
