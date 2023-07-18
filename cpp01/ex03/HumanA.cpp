/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:35:22 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/14 23:07:40 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), weapon(weapon) {}

HumanA::~HumanA(void) {}

void	HumanA::setName(std::string name)
{
	this->_name = name;
}

std::string HumanA::getName(void)
{
	return (this->_name);
}

void	HumanA::attack()
{
	std::cout << this->_name <<  " attacks with their " << weapon.getType() << std::endl;
}
