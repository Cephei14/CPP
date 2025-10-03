/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:20:32 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/10/03 00:49:26 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	
public:
	void set_first_name(std::string input);
	void set_last_name(std::string input);
	void set_nickname(std::string input);
	void set_phone_number(std::string input);
	void set_darkest_secret(std::string input);
	void print_first();
	void print_last();
	void print_nick();
	void formatted_size(std::string input);
	void print_contact();
};

#endif
