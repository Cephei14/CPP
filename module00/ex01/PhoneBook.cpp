/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:20:45 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/10/03 13:16:43 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook()
{
	this->idx = 0;
	contact_num = 0;
}
void PhoneBook::add()
{
	std::string f_name;
	std::string l_name;
	std::string n_name;
	std::string p_number;
	std::string secret;
	
	std::cout<<"Enter the contact's first name : ";
	std::getline(std::cin, f_name);
	if(std::cin.eof())
		return;
	while(f_name.empty())
	{
		if(std::cin.eof())
			return;
		std::cout << "invalid, Try again : ";
		std::getline(std::cin, f_name);
	}
	
	std::cout<<"\nEnter the last name : ";
	std::getline(std::cin, l_name);
	if(std::cin.eof())
		return;
	while(l_name.empty())
	{
		if(std::cin.eof())
			return;
		std::cout << "invalid, Try again : ";
		std::getline(std::cin, l_name);
	}
	std::cout<<"\nEnter the nickname : ";
	std::getline(std::cin, n_name);
	if(std::cin.eof())
		return;
	while(n_name.empty())
	{
		if(std::cin.eof())
			return;
		std::cout << "invalid, Try again : ";
		std::getline(std::cin, n_name);
	}
	std::cout<<"\nEnter the phone number : ";
	std::getline(std::cin, p_number);
	if(std::cin.eof())
		return;
	while(p_number.empty())
	{
		if(std::cin.eof())
			return;
		std::cout << "invalid, Try again : ";
		std::getline(std::cin, p_number);
	}
	std::cout<<"\nEnter the contact's darkest secret : ";
	std::getline(std::cin, secret);
	if(std::cin.eof())
		return;
	while(secret.empty())
	{
		if(std::cin.eof())
			return;
		std::cout << "invalid, Try again : ";
		std::getline(std::cin, secret);
	}
	this->contacts[this->idx].set_first_name(f_name);
	this->contacts[this->idx].set_last_name(l_name);
	this->contacts[this->idx].set_nickname(n_name);
	this->contacts[this->idx].set_phone_number(p_number);
	this->contacts[this->idx].set_darkest_secret(secret);
	this->idx++;
	if (contact_num<8)
		contact_num++;
	if(this->idx == 8)
		this->idx = 0;
}

void PhoneBook::search()
{
	std::cout<<std::endl;
	for (int x = 0; x < 45; x++)
		std::cout<<"-";
	std::cout<<std::endl;
	std::cout<<"|     index|first name| last name|  nickname|\n";
	for (int i = 0; i < 45; i++)
		std::cout<<"-";
	std::cout<<std::endl;
	for (int i = 0; i < contact_num; i++)
	{
		std::cout<<"|";
		std::cout<< std::setw(10) <<i+1;
		std::cout<<"|";
		contacts[i].print_first();
		std::cout<<"|";
		contacts[i].print_last();
		std::cout<<"|";
		contacts[i].print_nick();
		std::cout<<"|";
		std::cout<<std::endl;
	}
	for (int i = 0; i < 45; i++)
		std::cout<<"-";
	std::cout << std::endl;
	int index = 0;
	if(contact_num)
	{
		std::cout <<"Write the index to see more details\n";
		std::cin >> index;
		if (std::cin.fail())
		{
			std::cout << "Error\nEnter a number\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return;
		}
		if(std::cin.eof())
		{
			std::cout << "Error\nLeaving search...\n";
			return;
		}
		if((index > 0) && (index <= contact_num))
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			contacts[index - 1].print_contact();
		}
		else
			std::cout << "Index invalid\n";	
	}
}