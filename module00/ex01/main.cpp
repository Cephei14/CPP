/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:20:43 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/10/03 11:10:19 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{
	PhoneBook phonebook;
	std::string keyword_input;
	std::string str_input;

	while(1)
	{
		std::cout<<"\n-> To add a new contact use \"ADD\".\n";
		std::cout<<"-> To search for a contact use \"SEARCH\".\n";
		std::cout<<"-> To exit the phonebook use \"EXIT\".\n-------> ";
		std::cin>>keyword_input;
		if (std::cin.eof())
		{
			std::cout<<"CTRL+D\nLeaving . . ."<<std::endl;
			break;
		}
		if (keyword_input == "ADD")
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			phonebook.add();
		}
		else if (keyword_input == "SEARCH")
			phonebook.search();
		else if (keyword_input == "EXIT")
			break;
		if (std::cin.eof())
		{
			std::cout<<"CTRL+D\nLeaving . . ."<<std::endl;
			break;
		}
	}
	return 0;
}
