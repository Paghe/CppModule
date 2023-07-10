/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:49:24 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/09 18:32:04 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	Contact id;
	PhoneBook user;
	std::string detectCommand;

	user.printCommand();
	while (1)
	{
		getline(std::cin, detectCommand);
		if (std::cin.eof())
			exit(0);
		if (detectCommand == "ADD")
			user.addUser();
		else if (detectCommand == "SEARCH")
			user.searchUser();
		else if (detectCommand == "EXIT")
			exit(0);
		else
			std::cout << "Incorrect Input" << std::endl;
	}
	return (0);
}




/* 	std::string name;

	std::cout << "Give me the fucking number" << std::endl;
	std::cin >> name;
	id.setName(name);
	std::cout << "Your name is " + id.getName() << std::endl; */