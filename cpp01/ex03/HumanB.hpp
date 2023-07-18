/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:03:42 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/15 11:09:31 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB
{
	private:
			std::string	_name;
			Weapon	*weapon;
	public:
			HumanB(std::string name);
			~HumanB(void);
			void	setWeapon(Weapon &weapon);
			void	attack(void);
			
};

#endif