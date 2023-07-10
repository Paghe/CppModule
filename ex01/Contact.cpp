/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:33:22 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/06 20:33:54 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(void) {}
Contact::~Contact(void) {}

void	Contact::setName(std::string name)
{
	this->firstName = name;
}

void	Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void	Contact::setNickName(std::string nickName)
{
	this->nickName = nickName;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

std::string	Contact::getName(void)
{
	return (this->firstName);
}

std::string	Contact::getLastName(void)
{
	return (this->lastName);
}

std::string	Contact::getNickName(void)
{
	return (this->nickName);
}

std::string	Contact::getPhoneNumber(void)
{
	return (this->phoneNumber);
}

std::string	Contact::getDarkestSecret(void)
{
	return (this->darkestSecret);
}

