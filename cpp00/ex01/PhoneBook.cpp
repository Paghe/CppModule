/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:33:19 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/07 15:22:17 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void): idx(0){}
PhoneBook::~PhoneBook(void){}

void	PhoneBook::printCommand(void)
{
	std::cout << "Hello Welcome to the PhoneBook" << std::endl;
	std::cout << "Press \"ADD\" to save a new contact" << std::endl;
	std::cout << "Press \"SEARCH\" to dispaly a specific contact" << std::endl;
	std::cout << "Press \"EXIT\" to quit the programm" << std::endl;
}

Contact PhoneBook::getContact(int idx)
{
	return (this->contact[idx]);
}

bool	isAlphaString(const std::string &string)
{
	if (std::cin.eof())
		exit (0);
	if (string.empty())
		return (false);
	for (std::string::size_type	i = 0; i < string.length(); i++)
	{
		if (!std::isalpha(string[i]))
			return (false);
	}
	return (true);
}

std::string	PhoneBook::addUserName()
{
	std::string name;

	
	std::cout << "ADD NAME: ";
	getline(std::cin, name);
	if (!isAlphaString(name))
	{
		if (!name.empty())
		{	std::cout << "⛔️ DIGIT ARE NOT ALLOWED! ⛔️" << std::endl;
			name = std::string();
		}
	}
	while(name.empty())
	{
		std::cout << "PLEASE ADD YOUR NAME: ";
		if (std::cin.eof())
			exit(0);
		getline(std::cin, name);
		if (!isAlphaString(name))
		{
			if (!name.empty())
			{	std::cout << "⛔️ DIGIT ARE NOT ALLOWED! ⛔️" << std::endl;
				name = std::string();
			}
		}
		else
		{
			if (name.empty())
				std::cout << "PLEASE ADD YOUR NAME: ";
		}
	}
	return (name);
}

std::string	PhoneBook::addLastName()
{
	std::string lastName;

	
	std::cout << "ADD LAST NAME: ";
	getline(std::cin, lastName);
	if (!isAlphaString(lastName))
	{
		if (!lastName.empty())
		{	std::cout << "⛔️ DIGIT ARE NOT ALLOWED! ⛔️" << std::endl;
			lastName = std::string();
		}
	}
	while(lastName.empty())
	{
		std::cout << "PLEASE ADD YOUR LAST NAME: ";
		if (std::cin.eof())
			exit(0);
		getline(std::cin, lastName);
		if (!isAlphaString(lastName))
		{
			if (!lastName.empty())
			{	std::cout << "⛔️ DIGIT ARE NOT ALLOWED! ⛔️" << std::endl;
				lastName = std::string();
			}
		}
		else
		{
			if (lastName.empty())
				std::cout << "PLEASE ADD YOUR LAST NAME: ";
		}
	}
	return (lastName);
}

std::string	PhoneBook::addNickName()
{
	std::string nickName;

	
	std::cout << "ADD NICKNAME: ";
	getline(std::cin, nickName);
	if (nickName.empty())
	{
		if (std::cin.eof())
				exit(0);
		std::cout << "PLEASE ADD A NICKNAME: ";
		while (1)
		{
			if (std::cin.eof())
				exit(0);
			getline(std::cin, nickName);
			if (!nickName.empty())
				break ;
			else if (nickName.empty())
				std::cout << "PLEASE ADD A NICKNAME: ";
		}
	}
	return (nickName);
}

std::string	PhoneBook::addPhoneNumber()
{
	std::string phoneNumber;

	
	std::cout << "ADD PHONE NUMBER: ";
	getline(std::cin, phoneNumber);
	if (std::cin.eof())
			exit(0);
	if(phoneNumber.find_first_not_of("+0123456789") != std::string::npos)
	{
		if (!phoneNumber.empty())
		{	std::cout << "⛔️ ALPHA ARE NOT ALLOWED! ⛔️" << std::endl;
			phoneNumber = std::string();
		}
	}
	while(phoneNumber.empty())
	{
		std::cout << "PLEASE ADD YOUR PHONE NUMBER: ";
		getline(std::cin, phoneNumber);
		if (std::cin.eof())
			exit(0);
		if (phoneNumber.find_first_not_of("0123456789") != std::string::npos)
		{
			if (!phoneNumber.empty())
			{	std::cout << "⛔️ APLHA ARE NOT ALLOWED! ⛔️" << std::endl;
				phoneNumber = std::string();
			}
		}
	}
	return (phoneNumber);
}

std::string	PhoneBook::addDarkestSecret()
{
	std::string addDarkestSecret;

	
	std::cout << "YOUR DARKEST SECRET: ";
	getline(std::cin,  addDarkestSecret);
		if (addDarkestSecret.empty())
	{
		if (std::cin.eof())
				exit(0);
		std::cout << "PLEASE ADD A DARKEST SECRET: ";
		while (1)
		{
			if (std::cin.eof())
				exit(0);
			getline(std::cin, addDarkestSecret);
			if (!addDarkestSecret.empty())
				break ;
			else if (addDarkestSecret.empty())
				std::cout << "PLEASE ADD A DARKEST SECRET: ";
		}
	}
	return (addDarkestSecret);
}

void	PhoneBook::addUser(void)
{
	Contact c;

	c.setName(addUserName());
	c.setLastName(addLastName());
	c.setNickName(addNickName());
	c.setPhoneNumber(addPhoneNumber());
	c.setDarkestSecret(addDarkestSecret());
	this->contact[idx % 7] = c;
	idx++;
}