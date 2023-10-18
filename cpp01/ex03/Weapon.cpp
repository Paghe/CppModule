/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:35:32 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/15 11:46:34 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon(void) {}

std::string const& Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	if (this->_type.empty())
		std::cout <<"Please provide a type!" << std::endl;
	else
		this->_type = type;
}