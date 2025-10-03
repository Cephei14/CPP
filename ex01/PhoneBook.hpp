/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:20:34 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/10/02 23:25:15 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class PhoneBook
{
private:
	Contact contacts[8];
	int idx;
	int contact_num;

public:
	PhoneBook();
	void add();
	void search();
};

#endif