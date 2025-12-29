/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:20:30 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/10/03 13:10:09 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Contact::formatted_size(std::string input)
{
	int len = input.size();

	if(len < 10)
		std::cout<< std::setw(10) << input;
	else if(len == 10)
		std::cout << input;
	else
		std::cout << input.substr(0, 9) + ".";
}

void Contact::set_first_name(std::string input)
{
	first_name = input;
}

void Contact::set_last_name(std::string input)
{
	last_name = input;
}

void Contact::set_nickname(std::string input)
{
	nickname = input;
}

void Contact::set_phone_number(std::string input)
{
	phone_number = input;
}

void Contact::set_darkest_secret(std::string input)
{
	darkest_secret = input;
}

void Contact::print_first()
{
	formatted_size(first_name);
}

void Contact::print_last()
{
	formatted_size(last_name);
}

void Contact::print_nick()
{
	formatted_size(nickname);
}

void Contact::print_contact()
{
	std::cout<<"\nFirst name : "<<first_name<<std::endl;
	std::cout<<"Last name : "<<last_name<<std::endl;
	std::cout<<"Nick name : "<<nickname<<std::endl;
	std::cout<<"Phone Number : "<<phone_number<<std::endl;
	std::cout<<"Darkest Secret : "<<darkest_secret<<std::endl<<std::endl;
}
