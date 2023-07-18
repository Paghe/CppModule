/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:03:49 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/14 23:06:45 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private: 
			std::string _name;
			Weapon	&weapon;
	public:
			HumanA(std::string name, Weapon& weapon);
			~HumanA(void);
			std::string getName(void);
			void	setName(std::string name);
			void	attack(void);
			
			
};

#endif