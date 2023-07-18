/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:35:19 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/06 20:34:07 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Contact
{
	private: 
			std::string	firstName;
			std::string	lastName;
			std::string	nickName;
			std::string	phoneNumber;
			std::string	darkestSecret;
	public:
			void	setName(std::string name);
			void	setLastName(std::string lastName);
			void	setNickName(std::string nickName);
			void	setPhoneNumber(std::string phoneNumber);
			void	setDarkestSecret(std::string darkestSecret);
			std::string	getName(void);
			std::string	getLastName(void);
			std::string	getNickName(void);
			std::string	getPhoneNumber(void);
			std::string	getDarkestSecret(void);
			Contact(void);
			~Contact(void);
};

