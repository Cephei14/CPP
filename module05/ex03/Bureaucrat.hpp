#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class Bureaucrat
{

private:
	std::string const _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat& operator=(const Bureaucrat &other);
	~Bureaucrat();

	Bureaucrat(const std::string &name, int grade);
	std::string getName() const;
	int getGrade() const;
	void increment();
	void decrement();
	void signForm(AForm& f);
	void executeForm(AForm const & form) const;

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

std::ostream& operator <<(std::ostream& os, const Bureaucrat& b);

#endif