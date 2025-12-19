#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _IsSigned;
		const int _ToSign;
		const int _ToExecute;

	public:
		Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		Form(const std::string &name, const int ToSign, const int ToExecute);
		std::string get_name() const;
		bool getSigned() const;
		int get_ToSign() const;
		int get_ToExecute() const;
		void beSigned(const Bureaucrat &b);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream &os, const Form& f);

#endif