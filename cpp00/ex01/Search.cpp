/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:10:37 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/09 19:43:57 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	PhoneBook::printValidLength(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::searchUser(void)
{
	std:: string line;
	int			index;
	bool		flag;

	flag = false;
	index = 0;
	for(int i = 0; i < MAX_CONTACTS; i++)
	{
		if (getContact(i % 8).getName().empty())
				break;
		std::cout << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << printValidLength(getContact(i % 8).getName());
		std::cout << "|" << std::setw(10) << printValidLength(getContact(i % 8).getLastName());
		std::cout << "|" << std::setw(10) << printValidLength(getContact(i % 8).getNickName());
		std::cout << "|" << std::setw(10) << std::endl;
	}
	std::cout << "TYPE AN INDEX: " << std::endl;
	while(1)
	{
		getline(std::cin, line);
		if (std::cin.eof())
			exit(0);
		if (line.empty())
			std::cout << "PLEASE TYPE AN INDEX" << std::endl;
		else
		{
			if (line.find_first_not_of("0123456789") != std::string::npos)
			{
				std::cout << "WRONG INPUT" << std::endl;
				break ;
			}
			index = std::stoi(line);
			if (index >= idx || index > MAX_CONTACTS)
			{
				if (!flag)
					std::cout << "INDEX OUT OF RANGE" << std::endl;
				flag = true;
				break ;
			}
			else
			{
				std::cout << getContact(index).getName() << std::endl;
				std::cout << getContact(index).getLastName() << std::endl;
				std::cout << getContact(index).getNickName() << std::endl;
				std::cout << getContact(index).getPhoneNumber() << std::endl;
				std::cout << getContact(index).getDarkestSecret() << std::endl;
				std::cout << std::endl;
				break ;
			}
		}
	}
}