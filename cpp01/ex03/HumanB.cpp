/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:35:26 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/15 11:46:03 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) 
{
	this->weapon = nullptr;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (weapon == nullptr)
	{
		std::cout << this->_name << " has no weapon" << std::endl;
		return ;	
	}
	std::cout << this->_name <<  " attacks with their " << weapon->getType() << std::endl;
}

HumanB::~HumanB(void){}