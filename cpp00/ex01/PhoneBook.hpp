/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:35:26 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/09 18:28:41 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define	PHONEBOOK_HPP

#include <iostream>
#include <sstream>
#include "Contact.hpp"
#include <cctype>
#include <iomanip>
#define MAX_CONTACTS 8

class PhoneBook
{
	private:
			int	idx;
			Contact contact[MAX_CONTACTS];
	public:
			void		printCommand(void);
			Contact		getContact(int idx);
			std::string	addUserName();
			std::string	addLastName();
			std::string	addNickName();
			std::string	addPhoneNumber();
			std::string	addDarkestSecret();
			void		addUser();
			void		searchUser(void);
			std::string	printValidLength(std::string str);
			PhoneBook(void);
			~PhoneBook(void);
};

#endif