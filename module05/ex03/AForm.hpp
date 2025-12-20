#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _IsSigned;
		const int _ToSign;
		const int _ToExecute;

	public:
		AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		AForm(const std::string &name, const int ToSign, const int ToExecute);
		std::string get_name() const;
		bool getSigned() const;
		int get_ToSign() const;
		int get_ToExecute() const;
		void beSigned(const Bureaucrat &b);
		virtual void execute(Bureaucrat const& executor) const = 0;

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
	class SignException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream &os, const AForm& f);

#endif